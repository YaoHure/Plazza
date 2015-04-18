//
// EThread.hh for Plazza in /home/jibb/rendu/cpp_plazza/includes/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Sat Apr  18 11:49:21 2015 Jean-Baptiste Grégoire
// Last update Sat Apr  18 11:49:21 2015 Jean-Baptiste Grégoire
//

#ifndef ETHREAD_HH
# define ETHREAD_HH

# include <pthread.h>

#define NO_TIMEOUT	0

class EThread
{
public:
  EThread();
  int		launch(void *(*routine)(void *), void *args);
  bool	is_running() const;
  int		waitThread();
  ~EThread();
 
private:
  pthread_t	_thread;
  bool		_running; 
};

#endif // !ETHREAD_HH