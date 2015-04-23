//
// Pizza.cpp for Plazza in /home/jibb/rendu/cpp_plazza/src
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Fri Apr  17 15:41:12 2015 Jean-Baptiste Grégoire
// Last update Thu Apr 23 17:11:26 2015 Hugo Prenat
//

#include "Pizza.hh"

Pizza::Pizza(TypePizza type, TaillePizza size, int time) :
  _type(type), _size(size), _time(time)
{

}

std::vector<Ingredients *> const	*Pizza::getIngredients() const
{
  return (&_ingredients);
}

bool	Pizza::cook(float mult) const
{
  float	tmp = mult * static_cast<float>(_time);
  int	bake_time = static_cast<int>(tmp * 1000000.0);

  usleep(bake_time);
  return (true);
}

Pizza::~Pizza()
{

}
