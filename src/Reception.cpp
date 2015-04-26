//
// Reception.cpp for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 16:28:42 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 26 11:02:43 2015 Jean-Baptiste Grégoire
//

#include <sstream>
#include <algorithm>
#include "Reception.hh"

Reception::Reception(float mult, int nb_cooker, int stock_time) :
  _mult(mult), _nb_cooker(nb_cooker), _stock_time(stock_time)
{
  _typePizza.push_back("margarita");
  _typePizza.push_back("regina");
  _typePizza.push_back("americaine");
  _typePizza.push_back("fantasia");
  _sizePizza.push_back("S");
  _sizePizza.push_back("M");
  _sizePizza.push_back("L");
  _sizePizza.push_back("XL");
  _sizePizza.push_back("XXL");
  _quit = false;
}

long			getRealNbr(std::string const str)
{
  long			nbr = 0;
  int			i = 1;
  std::stringstream	ss_nbr;

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
  ss_nbr << str.substr(1, str.length());
  ss_nbr >> nbr;
  return (nbr);
}

void			Reception::createKitchen()
{
  Kitchen		*kitchen;

  kitchen = new Kitchen(_nb_cooker, _mult, _stock_time);
  kitchen->run();
  delete kitchen;
}

void			Reception::sendOrder(std::string const &type, std::string const &size)
{
  std::vector<NamedPipe *>::iterator it;
  std::string		answer;
  std::stringstream	ss;

  for (it = _toKitchen.begin(); it != _toKitchen.end(); ++it)
    {
      *(*it) << (type + " " + size);
      *(*_fromKitchen.begin()) >> answer;
      if (answer == "OK")
	return ;
    }
  if (_callKitchen.launch(son_fork, this) == -1)
    throw PlazzaErrorRuntime("fork(): Can't create the new kitchen !");
  ss << _callKitchen.getPid();
  _toKitchen.push_back(new NamedPipe(ss.str() + "_toKitchen"));
  _fromKitchen.push_back(new NamedPipe(ss.str() + "_fromKitchen"));
  *(*_toKitchen.begin()) << (type + " " + size);
  *(*_fromKitchen.begin()) >> answer;
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
  for (size_t i = 0; i <= semi_nbr; i++)
    {
      good = true;
      stream >> type;
      stream >> size;
      stream >> str_nbr;
      if (find(_typePizza.begin(), _typePizza.end(), type) == _typePizza.end())
	{
	  std::cerr << "Invalid type of pizza : " << type << std::endl;
	  good = false;
	}
      if (find(_sizePizza.begin(), _sizePizza.end(), size) == _sizePizza.end())
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
	  for (unsigned long i = 0; i != nbr; i++)
	    {
	      sendOrder(type, size);
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
  usleep(500);
  if (_manage.launch(startManageOrder, this) != 0)
    throw PlazzaErrorRuntime("Can't launch the Pizzeria !");
  return (true);
}

void		Reception::getInput()
{
  NamedPipe	nPipe(FIFO_OUTPUT);
  std::string	buf;
  char	c;

  while (buf != "quit")
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
  _manage.waitThread();
}

void			Reception::getOutput() const
{
  std::string		buf;
  int i = 1;

  while (!_quit)
    {
      NamedPipe		nPipe(FIFO_OUTPUT);
      while (nPipe.is_good())
	{
	  nPipe >> buf;
	  mvwprintw(_output, i, 5, "%s", buf.c_str());
	  wrefresh(_output);
	  i++;
	}
    }
}

void		Reception::manageOrder()
{
  std::string	queu;

  while (!_quit)
    {
      while (!_orders.empty() && (queu = _orders.front()) != "quit")
	{
	  parseOrder(queu); // factory;
	  _orders.pop();
	}
      if (queu == "quit")
	{
	  _orders.pop();
	  return ;
	}
      sleep(1);
    }
}

Reception::~Reception()
{
  while (!_toKitchen.empty())
    {
      delete _toKitchen.back();
      _toKitchen.pop_back();
    }
  while (!_fromKitchen.empty())
    {
      delete _fromKitchen.back();
      _fromKitchen.pop_back();
    }
  delwin(_output);
  delwin(_input);
  endwin();
}

void		*startManageOrder(void *p)
{
  reinterpret_cast<Reception *>(p)->manageOrder();
  return (NULL);
}

void		*startGetOutput(void *p)
{
  reinterpret_cast<Reception *>(p)->getOutput();
  return (NULL);
}
