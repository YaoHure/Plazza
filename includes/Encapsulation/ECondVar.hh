//
// ECondVar.hh for Plazza in /home/jibb/rendu/cpp_plazza/includes/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Fri Apr  17 21:22:52 2015 Jean-Baptiste Grégoire
// Last update Fri Apr 17 23:32:37 2015 Jean-Baptiste Grégoire
//

#ifndef ECONDVAR_HH
#define ECONDVAR_HH

# include <iostream>
# include <string>
# include <pthread.h>
# include <time.h>
# include "EMutex.hh"

class ECondVar
{
public:

  enum	Target
  {
    ONE = 0,
    BROADCAST
  };

  ECondVar();
  void	sleep(int sec);
  void	wakeUp(enum Target);
  ~ECondVar();

private:
  EMutex		_mutex;
  pthread_cond_t	_cond;
};

#endif // !ECONDVAR_HH
