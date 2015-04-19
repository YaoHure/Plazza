//
// Reception.cpp for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 16:28:42 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 19 18:27:59 2015 Hugo Prenat
//

#include <sstream>
#include <algorithm>

#include "Reception.hh"

Reception::Reception(float mult, int nb_cooker, int stock_time)
{
  _mult = mult;
  _nb_cooker = nb_cooker;
  _stock_time = stock_time;
  _typePizza["regina"] = Regina;
  _typePizza["margarita"] = Margarita;
  _typePizza["americaine"] = Americaine;
  _typePizza["fantasia"] = Fantasia;
  _sizePizza["S"] = S;
  _sizePizza["M"] = M;
  _sizePizza["L"] = L;
  _sizePizza["XL"] = XL;
  _sizePizza["XXL"] = XXL;
}

void		Reception::getInput()
{
  std::string	toto = "regina XXL x2; fantasia M x3; margarita S x1";

  parseOrder(toto);
  std::cout << toto << std::endl;
}

void			Reception::parseOrder(std::string &order)
{
  std::stringstream	stream;
  std::string		type;
  std::string		size;
  std::string		nbr;
  size_t		pos = 0;
  size_t		semi_nbr = std::count(order.begin(), order.end(), ';');

  while ((pos = order.find(";", pos)) != std::string::npos)
    {
      order.replace(pos, 1, " ; ");
      pos += 3;
    }
  stream << order;
  for (size_t i; i <= semi_nbr; i++)
    {
      stream >> type;
      stream >> size;
      stream >> nbr;
      if (_typePizza[type] == 0)
	{
	  std::cerr << "Invalid type of pizza : " << type << std::endl;
	  continue ;
	}
      if (_sizePizza[size] == 0)
	{
	  std::cerr << "Invalid size of pizza : " << size << std::endl;
	  continue ;
	}
      std::cout << "{" << type << "}" << std::endl;
      std::cout << "{" << size << "}" << std::endl;
      std::cout << "{" << nbr << "}" << std::endl;
      std::cout << _typePizza[type] << std::endl;
      stream >> nbr;
    }
}
