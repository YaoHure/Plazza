//
// main.cpp for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 20:57:20 2015 Hugo Prenat
// Last update Sun Apr 19 15:48:37 2015 Jean-Baptiste Grégoire
//

#include <iostream>
#include <cstdlib>

// TEMPORARY --> for the function sleep
#include <unistd.h>
// // // //

#include "Error.hh"
#include "Reception.hh"

Reception	*checkArg(int argc, char **argv)
{
  Reception	*rec;
  float		mult;
  int		nb_cooker, stock_time;

  if (argc != 4)
    throw PlazzaErrorArg("Usage: ./plazza [mult] [nb_cooker] [stock_time]");
  if ((mult = atof(argv[1])) < 0)
    throw PlazzaErrorArg("Error: [mult] must be >= 0");
  if ((nb_cooker = atoi(argv[2])) <= 0)
    throw PlazzaErrorArg("Error: [nb_cooker] must be > 0");
  if ((stock_time = atoi(argv[3])) <= 0)
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
      sleep(10);
      delete rec;
    }
  catch (PlazzaErrorArg const &err)
    {
      std::cout << err.what() << std::endl;
    }
  return (0);
}
