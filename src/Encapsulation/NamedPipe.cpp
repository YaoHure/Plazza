//
// NamedPipe.cpp for Plazza in /home/jibb/rendu/cpp_plazza/src/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Mon Apr 20 19:06:03 2015 Jean-Baptiste Grégoire
// Last update Mon Apr 20 23:07:20 2015 Jean-Baptiste Grégoire
//

#include "NamedPipe.hh"

NamedPipe::NamedPipe(char *name) : _name(name)
{
  struct stat	buf;

  if (stat(name, &buf) != -1)
    {
      if (mkfifo(name, S_IFIFO | 0666) != 0)
	throw PlazzaErrorRuntime("Can't create required ressource: NamedPipe");
    }
  _fs.open(name);
}

bool			NamedPipe::is_good() const
{
  return (_fs.good());
}

void			NamedPipe::operator>>(std::string &str)
{
  std::stringstream	tmp;

  tmp << _fs.rdbuf();
  str = tmp.str();
}

void			NamedPipe::operator<<(std::string const &str)
{
  _fs << str;
}

NamedPipe::~NamedPipe()
{
  _fs.close();
  unlink(_name);
}
