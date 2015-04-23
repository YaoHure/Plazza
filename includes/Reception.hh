//
// Reception.hh for Plazza in /home/jibb/rendu/cpp_plazza/includes
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 16:28:27 2015 Jean-Baptiste Grégoire
// Last update Thu Apr 23 23:38:22 2015 Jean-Baptiste Grégoire
//

#ifndef RECEPTION_HH_
# define RECEPTION_HH_

# include <sys/types.h>
# include <sys/stat.h>
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <curses.h>
# include <queue>
# include <cerrno>

# include "Plazza.hh"
# include "NamedPipe.hh"
# include "EThread.hh"
# include "Ingredients.hh"
# include "Pizza.hh"

# define	BUFF_SIZE	256
# define	FIFO_OUTPUT	"fifo_display"

class							Reception
{
public:
  Reception(float mult, int nb_cooker, int stock_time);
  ~Reception();

public:
  bool							launchUI();
  void							getInput();
  void							getOutput() const;
  void							manageOrder();
  void							putIngredient(std::string const &name,
								      std::string list[]);

private:
  void							parseOrder(std::string &order);

private:
  float							_mult;
  int							_nb_cooker;
  int							_stock_time;
  std::map<std::string, TypePizza>			_typePizza;
  std::map<std::string, TaillePizza>			_sizePizza;
  std::map<std::string, std::vector<Ingredients*> >	_ingredientList;
  std::map<std::string, int>				_timePizza;
  WINDOW						*_screen;
  WINDOW						*_output;
  WINDOW						*_input;
  int							_win_x;
  int							_win_y;
  int							_display_y;
  int							_curs_x;
  int							_curs_y;
  std::queue<std::string>				_orders;
  bool							_quit;
  EThread						_display;
};

void		*startGetOutput(void *p);

#endif // !RECEPTION_HH_
