//
// Cooker.hh for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza/includes
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Thu Apr 16 17:09:52 2015 Hugo Prenat
// Last update Fri Apr 17 16:15:17 2015 Hugo Prenat
//

#ifndef COOKER_HH_
# define COOKER_HH_

# include <string>

class	Cooker
{
 public:
  Cooker();
  ~Cooker();

 public:
  void	createPizza(std::string pizza, int size);

};

#endif /* !COOKER_HH_ */
