//
// EMutex.hh for Plazza in /home/jibb/rendu/cpp_plazza/includes/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Fri Apr  17 21:39:49 2015 Jean-Baptiste Grégoire
// Last update Fri Apr 17 23:31:33 2015 Jean-Baptiste Grégoire
//

#ifndef EMUTEX_HH
# define EMUTEX_HH

# include <pthread.h>

class EMutex
{
public:
  EMutex();

  int	lock();
  int	trylock();
  int	unlock();
  pthread_mutex_t *getMutex();

  ~EMutex();

private:
  pthread_mutex_t	_mutex;
};

#endif // !EMUTEX_HH
