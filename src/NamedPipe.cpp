//
// NamedPipe.cpp for Plazza in /home/jibb/rendu/cpp_plazza/src/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Mon Apr 20 19:06:03 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 26 19:08:09 2015 Jean-Baptiste Grégoire
//

#include "NamedPipe.hh"

NamedPipe::NamedPipe(std::string const &name) : _name(name)
{
  struct stat	buf;

  if (stat(name.c_str(), &buf) == -1)
    {
      if (mkfifo(name.c_str(), S_IFIFO | 0666) != 0)
	throw PlazzaErrorRuntime("Can't create required ressource: NamedPipe");
    }
}

bool			NamedPipe::is_good() const
{
  return (_ifs.good());
}

void			NamedPipe::set_good()
{
  _ifs.clear(std::ios::goodbit | std::ios::eofbit);
}

void			NamedPipe::operator>>(std::string &str)
{
  std::stringstream	buf;

  _ifs.open(_name.c_str(), std::ifstream::in);
  buf << _ifs.rdbuf();
  str.assign(buf.str());
  _ifs.close();
}

void			NamedPipe::operator<<(std::string const &str)
{
  _ofs.open(_name.c_str(), std::ofstream::out);
  _ofs << str;
  _ofs.close();
}

NamedPipe::~NamedPipe()
{
  unlink(_name.c_str());
}
