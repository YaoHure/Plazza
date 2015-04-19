//
// Reception.hh for Plazza in /home/jibb/rendu/cpp_plazza/includes
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 16:28:27 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 19 18:32:10 2015 Hugo Prenat
//

#ifndef RECEPTION_HH_
# define RECEPTION_HH_

# include <iostream>
# include <string>
# include <map>
# include <curses.h>

# include "Plazza.hh"

class					Reception
{
public:
  Reception(float mult, int nb_cooker, int stock_time);
  ~Reception();

public:
  void					getInput();
  bool					launchUI();
  std::string const			&getInput() const;
  void					getOutput() const;
  bool					manageOrder() const;

private:
  void					parseOrder(std::string &order);

private:
  float					_mult;
  int					_nb_cooker;
  int					_stock_time;
  std::map<std::string, TypePizza>	_typePizza;
  std::map<std::string, TaillePizza>	_sizePizza;
  WINDOW				*_screen;
  WINDOW				*_output;
  WINDOW				*_input;
  int					_win_x;
  int					_win_y;
};

#endif // !RECEPTION_HH_
