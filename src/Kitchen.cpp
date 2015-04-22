//
// Kitchen.cpp for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 15:28:13 2015 Hugo Prenat
// Last update Wed Apr 22 16:26:20 2015 Jean-Baptiste Grégoire
//

#include "Kitchen.hh"

Kitchen::Kitchen(unsigned int nbCooker, float mult, int stock_time) :
  _nbCooker(nbCooker), _nbPizza(0), _capacity(2 * nbCooker), _cookers(nbCooker),
  _mult(mult), _stock_time(stock_time)
{

}

bool			Kitchen::addOnePizza(APizza &pizza)
{
  cookerArgs		args;

  if (_capacity - _nbPizza == 0)
    return (false);
  _nbPizza += 1;
  args.pizza = &pizza;
  args.kitchen = this;
  _cookers.addWork(startCreatePizza, &args);
  return (true);
}

unsigned int		Kitchen::getFreeCooker() const
{
  return (_capacity - _nbPizza);
}

std::vector<AIngredients *> const *Kitchen::getAvailableIngredients() const
{
  return (&_ingredients);
}

float				Kitchen::getPreparationTime() const
{
  return (_mult);
}

int				Kitchen::getStockTime() const
{
  return (_stock_time);
}

Kitchen::~Kitchen()
{
}
