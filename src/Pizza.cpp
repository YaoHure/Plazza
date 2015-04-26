//
// Pizza.cpp for Plazza in /home/jibb/rendu/cpp_plazza/src
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Fri Apr  17 15:41:12 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 26 10:13:30 2015 Jean-Baptiste Grégoire
//

#include "Pizza.hh"

Pizza::Pizza(TypePizza type, TaillePizza size, int time, std::string const &name) :
  _type(type), _size(size), _time(time), _name(name)
{
  std::string	margarita[] = {"Doe", "Tomato", "Gruyere", ""};
  std::string	regina[] = {"Doe", "Tomato", "Gruyere", "Ham", "Mushrooms", ""};
  std::string	americaine[] = {"Doe", "Tomato", "Gruyere", "Steak", ""};
  std::string	fantasia[] = {"Doe", "Tomato", "Eggplant", "GoatCheese",
			      "ChiefLove", ""};

  putIngredient(Margarita, margarita);
  putIngredient(Regina, regina);
  putIngredient(Americaine, americaine);
  putIngredient(Fantasia, fantasia);
  _ingredients = _ingredientList[type];
}

void			Pizza::putIngredient(enum TypePizza type, std::string list[])
{
  for (int i = 0; list[i] != ""; i++)
    _ingredientList[type].push_back(new Ingredients(list[i]));
}

std::vector<Ingredients *> const	*Pizza::getIngredients() const
{
  return (&_ingredients);
}

std::string const	&Pizza::getName() const
{
  return (_name);
}

bool	Pizza::cook(float mult) const
{
  float	tmp = mult * static_cast<float>(_time);
  int	bake_time = static_cast<int>(tmp * 10000.0);

  usleep(bake_time);
  return (true);
}

Pizza::~Pizza()
{

}
