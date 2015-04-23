//
// Plazza.hh for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 11:39:10 2015 Jean-Baptiste Grégoire
// Last update Thu Apr 23 16:38:45 2015 Hugo Prenat
//

#ifndef PLAZZA_HH_
# define PLAZZA_HH_

# include <iostream>
# include <string>
# include "Error.hh"

enum	TypePizza
  {
    Regina = 1,
    Margarita = 2,
    Americaine = 4,
    Fantasia = 8
  };

enum	TaillePizza
  {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  };

#endif // PLAZZA_HH_
