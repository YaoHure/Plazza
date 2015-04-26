//
// Ingredients.cpp for Plaza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Tue Apr 21 23:54:27 2015 Hugo Prenat
// Last update Sun Apr 26 01:45:41 2015 Jean-Baptiste Grégoire
//

#include "Ingredients.hh"

Ingredients::Ingredients(std::string name) : _name(name), _quantity(0)
{}

std::string	Ingredients::getName() const
{
  return (_name);
}

unsigned long	Ingredients::getQuantity() const
{
  return (_quantity);
}

void		Ingredients::takeIngredient()
{
  _quantity -= 1;
}

void		Ingredients::addIngredient()
{
  _quantity += 1;
}

Ingredients::~Ingredients()
{
}
