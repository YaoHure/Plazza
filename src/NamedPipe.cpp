//
// NamedPipe.cpp for Plazza in /home/jibb/rendu/cpp_plazza/src/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Mon Apr 20 19:06:03 2015 Jean-Baptiste Grégoire
// Last update Tue Apr 21 11:32:00 2015 Jean-Baptiste Grégoire
//

#include "NamedPipe.hh"

NamedPipe::NamedPipe(std::string const &name) : _name(name)
{
  struct stat	buf;

  if (stat(name.c_str(), &buf) != -1)
    {
      if (mkfifo(name.c_str(), S_IFIFO | 0666) != 0)
	throw PlazzaErrorRuntime("Can't create required ressource: NamedPipe");
    }
  _fs.open(name.c_str());
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
  unlink(_name.c_str());
}
