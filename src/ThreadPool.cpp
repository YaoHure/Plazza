//
// ThreadPool.cpp for Plazza in /home/jibb/rendu/cpp_plazza/src/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Fri Apr  17 18:10:22 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 26 07:47:19 2015 Jean-Baptiste Grégoire
//

#include "ThreadPool.hh"

ThreadPool::ThreadPool(int nb_thread) : _size(nb_thread), _working(true)
{
  for (int i = 0; i < nb_thread; ++i)
  {
    EThread	*tmp = new EThread;

    if (tmp->launch(thread_start, this) != 0)
      throw std::runtime_error("Can't create threadpool !");
    _threads.push_back(tmp);
  }
}

void		ThreadPool::addWork(void *(*routine)(void *), void *args)
{
  Job	*newJob = new Job;

  newJob->func = routine;
  newJob->args = args;
  _jobs.push(newJob);
  _proc.wakeUp(ECondVar::ONE);
}

void		ThreadPool::stopThePool()
{
  _working = false;
}

void		ThreadPool::pendingFunc()
{
  bool		start = true;
  Job		*currentJob;

  while (start || _working)
  {
    if (_jobs.empty())
      _proc.sleep(NO_TIMEOUT);
    else
    {
      _mutex.lock();
      currentJob = _jobs.front();
      _jobs.pop();
      _mutex.unlock();
      (*(currentJob->func))(currentJob->args);
    }
    start = false;
  }
}

bool		ThreadPool::addNewThread(int nb_thread)
{
  for (int i = 0; i < nb_thread; ++i)
  {
    EThread *tmp = new EThread;

    if (tmp->launch(thread_start, this) != 0)
      throw ;
    _threads.push_back(tmp);
  }
  return (true);
}

ThreadPool::~ThreadPool()
{
  for (std::vector<EThread *>::iterator it = _threads.begin();
       it != _threads.end(); ++it)
    (*it)->waitThread();
  while (!_threads.empty())
  {
    delete _threads.back();
    _threads.pop_back();
  }
}

void	*thread_start(void *p)
{
  reinterpret_cast<ThreadPool *>(p)->pendingFunc();
  return (NULL);
}
