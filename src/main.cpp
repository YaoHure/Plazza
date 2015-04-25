//
// main.cpp for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 20:57:20 2015 Hugo Prenat
// Last update Fri Apr 24 18:07:07 2015 Jean-Baptiste Grégoire
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

Reception	*checkArg(int argc, char **argv)
{
  Reception	*rec;
  float		mult;
  int		nb_cooker, stock_time;

  if (argc != 4)
    throw PlazzaErrorArg("Usage: ./plazza [mult] [nb_cooker] [stock_time]");
  if (isParamNum(argv[1]) == 0 && (mult = atof(argv[1])) < 0)
    throw PlazzaErrorArg("Error: [mult] must be >= 0");
  if (isParamNum(argv[2]) == 0 && (nb_cooker = atoi(argv[2])) <= 0)
    throw PlazzaErrorArg("Error: [nb_cooker] must be > 0");
  if (isParamNum(argv[3]) == 0 && (stock_time = atoi(argv[3])) <= 0)
    throw PlazzaErrorArg("Error: [stock_time] must be > 0");
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
      rec->manageOrder();
      delete rec;
    }
  catch (const std::exception &err)
    {
      std::cerr << err.what() << std::endl;
    }
  return (0);
}
