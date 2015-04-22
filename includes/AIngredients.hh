//
// AIngredients.hh for Plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Tue Apr 21 23:55:33 2015 Hugo Prenat
// Last update Wed Apr 22 16:35:10 2015 Jean-Baptiste Grégoire
//

#ifndef AINGREDIENTS_HH_
# define AINGREDIENTS_HH_

# include "Plazza.hh"

class			AIngredients
{
public:
  AIngredients(Ingredients, std::string name, long quantity);
  virtual ~AIngredients() = 0;

public:
  std::string		getName() const;
  long			getQuantity() const;
  void			takeIngredient();

protected:
  const Ingredients	_ingredients;
  const std::string	_name;
  long			_quantity;
};

#endif // !AINGREDIENTS_HH_
