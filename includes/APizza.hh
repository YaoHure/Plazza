//
// Pizza.hh for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 11:34:50 2015 Jean-Baptiste Grégoire
// Last update Fri Apr 17 17:49:37 2015 Jean-Baptiste Grégoire
//

#ifndef APIZZA_HH_
# define APIZZA_HH_

# include "Plazza.hh"

class	APizza
{
public:
		APizza(TypePizza type, TaillePizza size, Ingredients ings, int time);
  bool		cook(double mult) const;
  virtual	~APizza();

protected:
  TypePizza	_type;
  TaillePizza	_size;
  Ingredients	_ingredients;
  int		_time;
};

#endif // !APIZZA_HH_
