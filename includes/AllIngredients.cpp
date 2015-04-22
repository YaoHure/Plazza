//
// Doe.hh for Plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Wed Apr 22 11:50:58 2015 Hugo Prenat
// Last update Wed Apr 22 14:45:34 2015 Hugo Prenat
//

#ifndef ALLINGREDIENTS_HH_
# define ALLINGREDIENTS_HH_

# include "AIngredients.hh"

class	Doe : public AIngredients
{
public:
  Doe(Ingredients ingr = DOE, std::string name = "doe", long quantity);
  ~Doe();
};

class	Tomato : public AIngredients
{
public:
  Tomato(Ingredients ing = TOMATO, std::string name = "tomato", long quantity);
  ~Tomato();
};

class	Gruyere : public AIngredients
{
public:
  Gruyere(Ingredients ingr = GRUYERE, std::string name = "gruiere", long quantity);
  ~Gruyere();
};

class	Ham : public AIngredients
{
public:
  Ham(Ingredients ingr = HAM, std::string name = "ham", long quantity);
  ~Ham();
};

class	Mushrooms : public AIngredients
{
public:
Mushrooms(Ingredients ingr = MUSHROOMS, std::string name = "mushrooms", long quantity);
~Mushrooms();
};

class	Steak : public AIngredients
{
public:
Steak(Ingredients ingr = STEAK, std::string name = "steak", long quantity);
  ~Steak();
};

class	Eggplant : public AIngredients
{
public:
Eggplant(Ingredients ingr = EGGPLANT, std::string name = "eggplant", long quantity);
  ~Eggplant();
};

class	GoatCheese : public AIngredients
{
public:
GoatCheese(Ingredients ingr = GOAT_CHEESE, std::string name = "goat cheese", long quantity);
~GoatCheese();
};

class	ChiefLive : public AIngredients
{
public:
  ChiefLive(Ingredients = CHIEF_LIVE, std::string name = "chief live", long quantity);
  ~ChiefLive();
};

#endif // !ALLINGREDIENTS_HH_
