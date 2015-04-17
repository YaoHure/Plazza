//
// Plazza.hh for Plazza in /home/jibb/rendu/cpp_plazza
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 11:39:10 2015 Jean-Baptiste Grégoire
// Last update Fri Apr 17 15:32:14 2015 Jean-Baptiste Grégoire
//

#ifndef PLAZZA_HH_
# define PLAZZA_HH_

# include <iostream>
# include <string>

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

enum	Ingredients
  {
    DOE = 1,
    TOMATO = 2,
    GRUYERE = 4,
    HAM = 8,
    MUSHROOMS = 16,
    STEAK = 32,
    EGGPLANT = 64,
    GOAT_CHEESE = 128,
    CHIEF_LIVE = 256
  };

#endif // PLAZZA_HH_
