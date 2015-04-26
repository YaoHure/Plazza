//
// Kitchen.cpp for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 15:28:13 2015 Hugo Prenat
// Last update Sun Apr 26 02:19:45 2015 Jean-Baptiste Grégoire
//

#include "Kitchen.hh"

Kitchen::Kitchen(unsigned int nbCooker, float mult, int stock_time) :
  _nbCooker(nbCooker), _nbPizza(0), _capacity(2 * nbCooker), _cookers(nbCooker),
  _mult(mult), _stock_time(stock_time)
{
  std::stringstream	ss;

  _typePizza["Regina"] = Regina;
  _typePizza["Margarita"] = Margarita;
  _typePizza["Americaine"] = Americaine;
  _typePizza["Fantasia"] = Fantasia;
  _sizePizza["S"] = S;
  _sizePizza["M"] = M;
  _sizePizza["L"] = L;
  _sizePizza["XL"] = XL;
  _sizePizza["XXL"] = XXL;
  _timePizza["margarita"] = 1 * _mult;
  _timePizza["regina"] = 2 * _mult;
  _timePizza["americaine"] = 2 * _mult;
  _timePizza["fantasia"] = 4 * _mult;
  _ingredients.push_back(new Ingredients("Doe"));
  _ingredients.push_back(new Ingredients("Tomato"));
  _ingredients.push_back(new Ingredients("Gruyere"));
  _ingredients.push_back(new Ingredients("Ham"));
  _ingredients.push_back(new Ingredients("Mushrooms"));
  _ingredients.push_back(new Ingredients("Steak"));
  _ingredients.push_back(new Ingredients("Eggplant"));
  _ingredients.push_back(new Ingredients("GoatCheese"));
  _ingredients.push_back(new Ingredients("ChiefLove"));
  ss << getpid();
  _fromRec = new NamedPipe(ss.str() + "_toKitchen");
  _toRec = new NamedPipe(ss.str() + "_fromKitchen");
  _regen.launch(startRegenIngredients, this);
}

bool			Kitchen::addOnePizza(Pizza *pizza)
{
  cookerArgs		*args = new cookerArgs;

  if (_capacity - _nbPizza == 0)
    return (false);
  _nbPizza += 1;
  args->pizza = pizza;
  args->kitchen = this;
  _cookers.addWork(startCreatePizza, args);
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
  std::string		type;
  std::string		size;

  while (42)
    {
      *_fromRec >> pizza;
      if (_capacity - _nbPizza > 0)
	{
	  type = pizza.substr(0, pizza.find(" "));
	  size = pizza.substr(pizza.find(" ") + 1, pizza.length());
	  Pizza *pizza = new Pizza(_typePizza[type], _sizePizza[size], _timePizza[type]);
	  addOnePizza(pizza);
	  _nbPizza += 1;
	  *_toRec << "OK";
	}
      else
	*_toRec << "KO";
    }
}

Kitchen::~Kitchen()
{
  while (!_ingredients.empty())
    {
      delete _ingredients.back();
      _ingredients.pop_back();
    }
  delete _fromRec;
  delete _toRec;
}

void				*startRegenIngredients(void *p)
{
  reinterpret_cast<Kitchen *>(p)->regenIngredients();
  return (NULL);
}
