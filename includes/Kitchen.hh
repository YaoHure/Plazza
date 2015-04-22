//
// Kitchen.hh for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 15:27:59 2015 Hugo Prenat
// Last update Wed Apr 22 16:24:34 2015 Jean-Baptiste Grégoire
//

#ifndef KITCHEN_HH_
# define KITCHEN_HH_

# include <iostream>
# include <string>
# include <vector>
# include "APizza.hh"
# include "ThreadPool.hh"

class				Kitchen
{
public:
  Kitchen(unsigned int nbCooker, float mult, int stock_time);
  ~Kitchen();

public:
  unsigned int			getFreeCooker() const;
  std::vector<AIngredients *> const	*getAvailableIngredients() const;
  float				getPreparationTime() const;
  int				getStockTime() const;

public:
  bool				addOnePizza(APizza &pizza);

private:
  unsigned int			_nbCooker;
  unsigned int			_nbPizza;
  unsigned int			_capacity;
  ThreadPool			_cookers;
  float				_mult;
  int				_stock_time;
  std::vector<APizza *>		_order;
  std::vector<AIngredients *>	_ingredients;
};

typedef struct
{
  APizza	*pizza;
  Kitchen	*kitchen;
}		cookerArgs;

void				*startCreatePizza(void *p);

#endif // !KITCHEN_HH_
