//
// Pizza.hh for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 11:34:50 2015 Jean-Baptiste Grégoire
// Last update Thu Apr 23 16:46:58 2015 Hugo Prenat
//

#ifndef PIZZA_HH_
# define PIZZA_HH_

# include <unistd.h>
# include <vector>

# include "Plazza.hh"
# include "Ingredients.hh"

class					Pizza
{
public:
  Pizza(TypePizza type, TaillePizza size, int time);
  ~Pizza();

public:
  bool					cook(float mult) const;

public:
  std::vector<Ingredients *> const	*getIngredients() const;

protected:
  TypePizza				_type;
  TaillePizza				_size;
  int					_time;
  std::vector<Ingredients*>		_ingredients;
};

#endif // !PIZZA_HH_
