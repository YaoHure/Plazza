//
// Reception.cpp for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 16:28:42 2015 Jean-Baptiste Grégoire
// Last update Thu Apr 23 23:09:50 2015 Jean-Baptiste Grégoire
//

#include <sstream>
#include <algorithm>
#include "Reception.hh"

Reception::Reception(float mult, int nb_cooker, int stock_time) :
  _mult(mult), _nb_cooker(nb_cooker), _stock_time(stock_time)
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
  _quit = false;
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
      if (buf != "quit")
	_orders.push(buf);
      wmove(_input, _curs_y, _curs_x);
      for (size_t i = 0; i != buf.length(); i++)
	wprintw(_input, " ");
      wmove(_input, _curs_y, _curs_x);
      nPipe << buf;
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
      mvwprintw(_output, i, 5, "*** %s ***", buf.c_str());
      wrefresh(_output);
      i++;
    }
}

bool		Reception::manageOrder() const
{
  return (true);
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
