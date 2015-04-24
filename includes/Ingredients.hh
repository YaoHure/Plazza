//
// AIngredients.hh for Plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Tue Apr 21 23:55:33 2015 Hugo Prenat
// Last update Fri Apr 24 03:19:20 2015 Jean-Baptiste Grégoire
//

#ifndef INGREDIENTS_HH_
# define INGREDIENTS_HH_

# include <string>

class			Ingredients
{
public:
  Ingredients(std::string name);
  ~Ingredients();

public:
  std::string		getName() const;
  unsigned long		getQuantity() const;
  void			takeIngredient();
  void			addIngredient();

protected:
  const std::string	_name;
  unsigned long		_quantity;
};

#endif // !INGREDIENTS_HH_
