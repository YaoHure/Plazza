//
// NamedPipe.hh for Plazza in /home/jibb/rendu/cpp_plazza/src/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Mon Apr 20 19:06:26 2015 Jean-Baptiste Grégoire
// Last update Mon Apr 20 23:31:24 2015 Jean-Baptiste Grégoire
//

#ifndef NAMEDPIPE_HH_
# define NAMEDPIPE_HH_

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sstream>
# include <fstream>
# include "Plazza.hh"

class		NamedPipe
{
public:
  NamedPipe(std::string const &name);
  bool		is_good() const;
  void		operator>>(std::string &str);
  void		operator<<(std::string const &str);
  ~NamedPipe();

private:
  std::string const	_name;
  std::fstream		_fs;
};

#endif // !NAMEDPIPE_HH_
