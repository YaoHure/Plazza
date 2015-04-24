//
// Cooker.cpp for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 15:26:41 2015 Hugo Prenat
// Last update Fri Apr 24 03:47:51 2015 Jean-Baptiste Grégoire
//

#include "Cooker.hh"

Cooker::Cooker(Kitchen *kitchen) : _kitchen(kitchen)
{

}

bool	Cooker::manageIngredient(Pizza const *pizza, enum Action action)
{
  std::vector<Ingredients *> const	*availIngr = _kitchen->getAvailableIngredients();
  std::vector<Ingredients *> const	*requIngr = pizza->getIngredients();
  std::vector<Ingredients *>::const_iterator pizzaIt;
  std::vector<Ingredients *>::const_iterator kitchenIt;
  unsigned int			nbIngr(0);

  for (pizzaIt = requIngr->begin(); pizzaIt != requIngr->end(); ++pizzaIt)
    {
      nbIngr = 0;
      for (kitchenIt = availIngr->begin(); kitchenIt != availIngr->end(); ++kitchenIt)
	{
	  if ((*pizzaIt)->getName() == (*kitchenIt)->getName())
	    {
	      nbIngr = (*kitchenIt)->getQuantity();
	      break ;
	    }
	}
      if (action == GET && nbIngr > 0)
	(*kitchenIt)->takeIngredient();
      if (action == CHECK && nbIngr == 0)
	return (false);
    }
  return (true);
}

bool				Cooker::createPizza(Pizza const *pizza)
{
  NamedPipe			_output(FIFO_OUTPUT);

  // mutex lock
  std::cout << "coucou" << std::endl;
  if (manageIngredient(pizza, CHECK))
    manageIngredient(pizza, GET);
  pizza->cook(_kitchen->getPreparationTime());
  _output << "Pizza finis ! (I don't have name anymore)";
  // mutex unlock
  return (true);
}

Cooker::~Cooker()
{

}

void				*startCreatePizza(void *p)
{
  Cooker			*cooker;
  cookerArgs			*args = reinterpret_cast<cookerArgs *>(p);

  cooker = new Cooker(args->kitchen);
  cooker->createPizza(args->pizza);
  delete cooker;
  return (NULL);
}
