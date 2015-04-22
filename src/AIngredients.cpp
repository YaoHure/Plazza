//
// AIngredients.cpp for Plaza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Tue Apr 21 23:54:27 2015 Hugo Prenat
// Last update Wed Apr 22 11:44:14 2015 Hugo Prenat
//

#include "AIngredients.hh"

AIngredients::AIngredients(Ingredients type, std::string name, long quantity) :
  _ingredients(type), _name(name), _quantity(quantity)
{}

std::string	AIngredients::getName() const
{
  return (_name);
}

long	AIngredients::getQuantity() const
{
  return (_quantity);
}

void	AIngredients::takeIngredient()
{
  _quantity -= 1;
}
