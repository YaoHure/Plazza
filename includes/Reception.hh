//
// Reception.hh for Plazza in /home/jibb/rendu/cpp_plazza/includes
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 16:28:27 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 26 10:30:23 2015 David Tran
//

#ifndef RECEPTION_HH_
# define RECEPTION_HH_

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <curses.h>
# include <queue>
# include <cerrno>
# include <sstream>
# include <algorithm>

# include "Plazza.hh"
# include "NamedPipe.hh"
# include "EThread.hh"
# include "Ingredients.hh"
# include "Pizza.hh"
# include "Kitchen.hh"
# include "EFork.hh"

# define	BUFF_SIZE	256

class	EFork;

class				Reception
{
public:
  Reception(float mult, int nb_cooker, int stock_time);
  ~Reception();

public:
  bool				launchUI();
  void				getInput();
  void				getOutput() const;
  void				manageOrder();
  void				sendOrder(std::string const &type, std::string const &size);
  void				createKitchen();
private:
  void				parseOrder(std::string &order);

private:
  float				_mult;
  int				_nb_cooker;
  int				_stock_time;
  std::vector<std::string>	_typePizza;
  std::vector<std::string>	_sizePizza;
  std::vector<NamedPipe *>	_toKitchen;
  std::vector<NamedPipe *>	_fromKitchen;
  WINDOW			*_screen;
  WINDOW			*_output;
  WINDOW			*_input;
  int				_win_x;
  int				_win_y;
  int				_display_y;
  int				_curs_x;
  int				_curs_y;
  std::queue<std::string>	_orders;
  bool				_quit;
  EThread			_display;
  EThread			_manage;
  EFork				_callKitchen;
};

void		*startGetOutput(void *p);
void		*startManageOrder(void *p);
void		son_fork(void *);

#endif // !RECEPTION_HH_
