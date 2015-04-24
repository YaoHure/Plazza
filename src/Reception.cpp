//
// Reception.cpp for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 16:28:42 2015 Jean-Baptiste Grégoire
// Last update Fri Apr 24 03:45:54 2015 Jean-Baptiste Grégoire
//

#include <sstream>
#include <algorithm>
#include "Reception.hh"

Reception::Reception(float mult, int nb_cooker, int stock_time) :
  _mult(mult), _nb_cooker(nb_cooker), _stock_time(stock_time)
{
  std::string	margarita[] = {"Doe", "Tomato", "Gruyere", ""};
  std::string	regina[] = {"Doe", "Tomato", "Gruyere", "Ham", "Mushrooms", ""};
  std::string	americaine[] = {"Doe", "Tomato", "Gruyere", "Steak", ""};
  std::string	fantasia[] = {"Doe", "Tomato", "Eggplant", "GoatCheese",
			      "ChiefLove", ""};

  _typePizza["margarita"] = Margarita;
  _typePizza["regina"] = Regina;
  _typePizza["americaine"] = Americaine;
  _typePizza["fantasia"] = Fantasia;
  _sizePizza["S"] = S;
  _sizePizza["M"] = M;
  _sizePizza["L"] = L;
  _sizePizza["XL"] = XL;
  _sizePizza["XXL"] = XXL;
  _timePizza["margarita"] = 1 * _mult;
  _timePizza["regina"] = 2 * _mult;
  _timePizza["americaine"] = 2 * _mult;
  _timePizza["fantasia"] = 4 * _mult;
  putIngredient("margarita", margarita);
  putIngredient("regina", regina);
  putIngredient("americaine", americaine);
  putIngredient("fantasia", fantasia);
  _quit = false;
}

void	Reception::putIngredient(std::string const &name, std::string list[])
{
  for (int i = 0; list[i] != ""; i++)
    _ingredientList[name].push_back(new Ingredients(list[i]));
}

long	getRealNbr(std::string const str)
{
  long	nbr = 0;
  int	i = 1;

  if (str[0] != 'x')
    return (-1);
  if (str[i] == '-')
    return (-1);
  if (str.length() < 1)
    return (-1);
  while (str[i])
    {
      if (isalpha(str[i]) != 0)
	return (-1);
      i++;
    }
  return (nbr);
}

void			Reception::sendPizza(Pizza &pizza)
{
  std::vector<Kitchen*>::iterator it;
  bool			sent = false;
  int			pid;

  for (it = _headquarters.begin(); it != _headquarters.end(); ++it)
    {
      if ((*it)->getFreeCooker() > 0)
	{
	  (*it)->addOnePizza(pizza);
	  sent = true;
	  break;
	}
    }
  if (!sent)
    {
      _headquarters.push_back(new Kitchen(_nb_cooker, _mult, _stock_time));
      if ((pid = fork()) == -1)
	throw PlazzaErrorRuntime("fork(): Can't create new kitchen !");
      if (pid == 0)
	_headquarters.back()->addOnePizza(pizza);
      else
	waitpid(pid, NULL, WNOHANG);
    }
}

void			Reception::parseOrder(std::string &order)
{
  std::stringstream	stream;
  std::string		type;
  std::string		size;
  std::string		str_nbr;
  size_t		pos = 0;
  size_t		semi_nbr = std::count(order.begin(), order.end(), ';');
  unsigned long		nbr = 0;
  bool			good;

  while ((pos = order.find(";", pos)) != std::string::npos)
    {
      order.replace(pos, 1, " ; ");
      pos += 3;
    }
  stream << order;
  for (size_t i; i <= semi_nbr; i++)
    {
      good = true;
      stream >> type;
      stream >> size;
      stream >> str_nbr;
      if (_typePizza[type] == 0)
	{
	  std::cerr << "Invalid type of pizza : " << type << std::endl;
	  good = false;
	}
      if (_sizePizza[size] == 0)
	{
	  std::cerr << "Invalid size of pizza : " << size << std::endl;
	  good = false;
	}
      if ((nbr = getRealNbr(str_nbr)) <= 0)
	{
	  std::cerr << "Invalid number of pizza : " << str_nbr << std::endl;
	  good = false;
	}
      stream >> str_nbr;
      if (good)
	{
	  for (unsigned long i; i != nbr; i++)
	    {
	      Pizza *tmp = new Pizza(_typePizza[type], _sizePizza[size], _timePizza[type]); // creation de la pizza
	      sendPizza(*tmp);
	    }
	}
    }
}

bool      Reception::launchUI()
{
  int		out_x, out_y;

  if ((_screen = initscr()) == NULL)
    throw PlazzaErrorRuntime("Initialisation failed !");
  getmaxyx(_screen, _win_y, _win_x);
  if ((_output = newwin(static_cast<int>(9.0 / 10.0 * static_cast<float>(_win_y)), _win_x, 0, 0)) == NULL)
    throw PlazzaErrorRuntime("Initialisation failed !");
  getmaxyx(_output, out_y, out_x);
  if ((_input = newwin(_win_y - out_y, _win_x, out_y, 0)) == NULL)
    throw PlazzaErrorRuntime("Initialisation failed !");
  curs_set(0);
  box(_output, '|', '-');
  box(_input, '|', '-');
  scrollok(_output, TRUE);
  wmove(_input, getcury(_input) + 2, 5);
  wprintw(_input, "> ");
  _curs_y = getcury(_input);
  _curs_x = getcurx(_input);
  _display_y = 1;
  wrefresh(_output);
  wrefresh(_input);
  if (_display.launch(startGetOutput, this) != 0)
    throw PlazzaErrorRuntime("Can't launch the output screen !");
//  refresh();
  return (true);
}

void		Reception::getInput()
{
  NamedPipe	nPipe(FIFO_OUTPUT);
  std::string	buf;
  char	c;

  while (buf != "quit\n")
    {
      buf.clear();
      c = 0;
      while (c != '\n')
	{
	  c = wgetch(_input);
	  if (c == 27)
	    {
	      _quit = true;
	      return ;
	    }
	  buf.push_back(c);
	}
      _orders.push(buf);
      wmove(_input, _curs_y, _curs_x);
      for (size_t i = 0; i != buf.length(); i++)
	wprintw(_input, " ");
      wmove(_input, _curs_y, _curs_x);
    }
  _quit = true;
  _display.waitThread();
}

void			Reception::getOutput() const
{
  NamedPipe		nPipe(FIFO_OUTPUT);
  std::string		buf;
  int i = 1;

  while (nPipe.is_good() && !_quit)
    {
      nPipe >> buf;
      mvwprintw(_output, i, 5, "%s", buf.c_str());
      wrefresh(_output);
      i++;
    }
}

void		Reception::manageOrder()
{
  std::string	queu;

  while ((queu = _orders.front()) != "quit")
    {
      parseOrder(queu); // factory;
      _orders.pop();
    }
  _orders.pop();
}

Reception::~Reception()
{
  delwin(_output);
  delwin(_input);
  endwin();
}

void		*startGetOutput(void *p)
{
  reinterpret_cast<Reception *>(p)->getOutput();
  return (NULL);
}
