//
// Kitchen.cpp for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 15:28:13 2015 Hugo Prenat
// Last update Fri Apr 24 03:34:55 2015 Jean-Baptiste Grégoire
//

#include "Kitchen.hh"

Kitchen::Kitchen(unsigned int nbCooker, float mult, int stock_time) :
  _nbCooker(nbCooker), _nbPizza(0), _capacity(2 * nbCooker), _cookers(nbCooker),
  _mult(mult), _stock_time(stock_time)
{
  _regen.launch(startRegenIngredients, this);
}

bool			Kitchen::addOnePizza(Pizza &pizza)
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

std::vector<Ingredients *> const *Kitchen::getAvailableIngredients() const
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

void				Kitchen::regenIngredients()
{
  std::vector<Ingredients *>::iterator it;

  sleep(1);
  while (1)
    {
      for (it = _ingredients.begin(); it != _ingredients.end(); ++it)
	(*it)->addIngredient();
      usleep(_stock_time);
    }
}

Kitchen::~Kitchen()
{
}

void				*startRegenIngredients(void *p)
{
  reinterpret_cast<Kitchen *>(p)->regenIngredients();
  return (NULL);
}
