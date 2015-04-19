//
// Reception.cpp for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 16:28:42 2015 Jean-Baptiste Grégoire
// Last update Fri Apr 17 23:17:15 2015 Hugo Prenat
//

#include "Reception.hh"

Reception::Reception(float mult, int nb_cooker, int stock_time) :
  _mult(mult), _nb_cooker(nb_cooker), _stock_time(stock_time)
{
  if ((_screen = initscr()) == NULL)
    throw ;
  getmaxyx(_screen, _win_y, _win_x);
}

bool      Reception::launchUI()
{
  int		out_x, out_y;

  if ((_output = newwin(static_cast<int>(9.0 / 10.0 * static_cast<float>(_win_y)), _win_x, 0, 0)) == NULL)
    throw ;
  getmaxyx(_output, out_y, out_x);
  if ((_input = newwin(_win_y - out_y, _win_x, out_y, 0)) == NULL)
    throw ;
  curs_set(0);
  box(_output, '|', '-');
  box(_input, '|', '-');
  scrollok(_output, TRUE);
  wrefresh(_output);
  wrefresh(_input);
//  refresh();
  return (true);
}

std::string const &Reception::getInput() const
{
  return (NULL);
}

void      Reception::getOutput() const
{

}

bool      Reception::manageOrder() const
{
  return (true);
}

Reception::~Reception()
{
  delwin(_output);
  delwin(_input);
  endwin();
}