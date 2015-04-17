//
// EThread.hh for Plazza in /home/jibb/rendu/cpp_plazza/includes/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Fri Apr  17 18:04:17 2015 Jean-Baptiste Grégoire
// Last update Fri Apr  17 18:04:17 2015 Jean-Baptiste Grégoire
//

#ifndef ETHREAD_HH
#define ETHREAD_HH

# include <pthread.h>

class	EThread
{
public:
  EThread();
  pthread	*getThread() const;
  bool		addNewThread();
  void		pushThreadBack(pthread_t *thread);
  ~EThread();

private:
  std::vector<std::pair<pthread_t *, bool> >	_threads;
};

#endif // !ETHREAD_HH