//
// Pizza.hh for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 11:34:50 2015 Jean-Baptiste Grégoire
// Last update Wed Apr 22 16:34:46 2015 Jean-Baptiste Grégoire
//

#ifndef APIZZA_HH_
# define APIZZA_HH_

# include <unistd.h>
# include <vector>
# include "Plazza.hh"
# include "AIngredients.hh"

class	APizza
{
public:
  APizza(TypePizza type, TaillePizza size, int time);
  virtual	~APizza() = 0;

public:
  bool		cook(float mult) const;

public:
  std::vector<AIngredients *> const	*getIngredients() const;

protected:
  TypePizza	_type;
  TaillePizza	_size;
  int		_time;
  std::vector<AIngredients *> _ingredients;
};

#endif // !APIZZA_HH_
