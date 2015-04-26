//
// Pizza.hh for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 11:34:50 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 26 10:17:02 2015 Jean-Baptiste Grégoire
//

#ifndef PIZZA_HH_
# define PIZZA_HH_

# include <unistd.h>
# include <vector>
# include <map>

# include "Plazza.hh"
# include "Ingredients.hh"

class					Pizza
{
public:
  Pizza(TypePizza type, TaillePizza size, int time, std::string const &name);
  ~Pizza();

public:
  bool					cook(float mult) const;
  void					putIngredient(enum TypePizza type,
						      std::string list[]);
public:
  std::vector<Ingredients *> const	*getIngredients() const;
  std::string const			&getName() const;
  void					setIngredients(std::vector<Ingredients *> &ingredients);

protected:
  TypePizza				_type;
  TaillePizza				_size;
  int					_time;
  std::string const			_name;
  std::map<TypePizza, std::vector<Ingredients*> >	_ingredientList;
  std::vector<Ingredients*>		_ingredients;
};

#endif // !PIZZA_HH_
