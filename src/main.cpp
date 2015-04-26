//
// main.cpp for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 20:57:20 2015 Hugo Prenat
// Last update Sun Apr 26 19:27:07 2015 Jean-Baptiste Grégoire
//

#include <iostream>
#include <cstdlib>
#include "Error.hh"
#include "Reception.hh"

int	isParamNum(char *str)
{
  int	i = 0;

  if (str[i] == '-')
    i++;
  while (str[i])
    {
      if (isalpha(str[i]) != 0 && str[i] != '.')
	throw PlazzaErrorArg(std::string("Error: ") + str +
			     ", Bad arguments, must be a digit integer");
      i++;
    }
  return (0);
}

Reception		*checkArg(int argc, char **argv)
{
  Reception		*rec;
  std::stringstream	ss;
  float			mult(0.0);
  int			nb_cooker(0), stock_time(0);

  if (argc != 4)
    throw PlazzaErrorArg("Usage: ./plazza [mult] [nb_cooker] [stock_time]");
  if (isParamNum(argv[1]) == 0 && isParamNum(argv[2]) == 0 && isParamNum(argv[3]) == 0)
    {
      ss.str(std::string(argv[1]));
      ss >> mult;
      if (mult < 0.0)
	throw PlazzaErrorArg("Error: [mult] must be >= 0");
      ss.clear();
      ss.str(std::string(argv[2]));
      ss >> nb_cooker;
      if (nb_cooker <= 0)
	throw PlazzaErrorArg("Error: [nb_cooker] must be > 0");
      ss.clear();
      ss.str(std::string(argv[3]));
      ss >> stock_time;
      if (stock_time <= 0)
	throw PlazzaErrorArg("Error: [stock_time] must be > 0");
    }
  if (mult == 0.f)
    mult = 1;
  rec = new Reception(mult, nb_cooker, stock_time);
  return (rec);
}

int		main(int argc, char **argv)
{
  Reception	*rec;

  try
    {
      rec = checkArg(argc, argv);
      rec->launchUI();
      rec->getInput();
      delete rec;
    }
  catch (const std::exception &err)
    {
      std::cerr << err.what() << std::endl;
    }
  return (0);
}
