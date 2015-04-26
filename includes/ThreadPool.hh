//
// ThreadPool.hh for Plazza in /home/jibb/rendu/cpp_plazza/includes/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Fri Apr  17 18:04:17 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 26 07:45:53 2015 Jean-Baptiste Grégoire
//

#ifndef THREADPOOL_HH
#define THREADPOOL_HH

# include <vector>
# include <queue>
# include <exception>
# include <stdexcept>
# include "EThread.hh"
# include "ECondVar.hh"
# include "EMutex.hh"

void	*thread_start(void *p);

class	ThreadPool
{
public:
  ThreadPool(int nb_thread);
  ~ThreadPool();

public:
  bool    addNewThread(int nb_thread);
  void    addWork(void *(*routine)(void *), void *args);
  void    pendingFunc();
  void    stopThePool();

private:
  typedef struct
  {
    void	*(*func)(void *);
    void	*args;
  }		Job;

private:
  int   _size;
  bool	_working;
  std::vector<EThread *>	_threads;
  std::queue<Job *>		_jobs;
  ECondVar			_proc;
  EMutex			_mutex;
};

#endif // !THREADPOOL_HH
