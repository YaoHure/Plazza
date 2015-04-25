//
// Kitchen.cpp for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 15:28:13 2015 Hugo Prenat
// Last update Sat Apr 25 18:09:45 2015 Jean-Baptiste Grégoire
//

#include "Kitchen.hh"

Kitchen::Kitchen(unsigned int nbCooker, float mult, int stock_time) :
  _nbCooker(nbCooker), _nbPizza(0), _capacity(2 * nbCooker), _cookers(nbCooker),
  _mult(mult), _stock_time(stock_time)
{
  std::stringstream	ss;
  std::string	margarita[] = {"Doe", "Tomato", "Gruyere", ""};
  std::string	regina[] = {"Doe", "Tomato", "Gruyere", "Ham", "Mushrooms", ""};
  std::string	americaine[] = {"Doe", "Tomato", "Gruyere", "Steak", ""};
  std::string	fantasia[] = {"Doe", "Tomato", "Eggplant", "GoatCheese",
			      "ChiefLove", ""};

  _timePizza["margarita"] = 1 * _mult;
  _timePizza["regina"] = 2 * _mult;
  _timePizza["americaine"] = 2 * _mult;
  _timePizza["fantasia"] = 4 * _mult;
  putIngredient("margarita", margarita);
  putIngredient("regina", regina);
  putIngredient("americaine", americaine);
  putIngredient("fantasia", fantasia);
  ss << getpid();
  _fromRec = new NamedPipe(ss.str() + "_toKitchen");
  _toRec = new NamedPipe(ss.str() + "_fromKitchen");
  _regen.launch(startRegenIngredients, this);
}

void			Kitchen::putIngredient(std::string const &name, std::string list[])
{
  for (int i = 0; list[i] != ""; i++)
    _ingredientList[name].push_back(new Ingredients(list[i]));
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

void			Kitchen::run()
{
  std::string		pizza;

  while (42)
    {
      _fromRec >> pizza;
      if (_capacity - nbPizza > 0)
	{
	  Pizza *pizza = new Pizza;
	  _nbPizza += 1;
	  _toRec << "OK";
	}
      else
	_toRec << "KO";
    }
}

Kitchen::~Kitchen()
{
}

void				*startRegenIngredients(void *p)
{
  delete _fromRec;
  delete _toRec;
  reinterpret_cast<Kitchen *>(p)->regenIngredients();
  return (NULL);
}
