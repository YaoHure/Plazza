//
// EThread.cpp for Plazza in /home/jibb/rendu/cpp_plazza/src/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Fri Apr  17 18:10:22 2015 Jean-Baptiste Grégoire
// Last update Fri Apr  17 18:10:22 2015 Jean-Baptiste Grégoire
//

#include "EThread.hh"

EThread::EThread(int nb_thread)
{
  for (int i = 0; i < nb_thread; ++i)
  {
    pthread_t	*thread_tmp = new pthread_t;
    std::pair<pthread_t *, bool> tmp(thread_tmp, true);

    if (pthread_create(tmp.first, NULL, pendingFunc, NULL) != 0)
      throw ;
    _threads.push_back(tmp);
  }
}

pthread *getThread() const
{
  std::vector<std::pair<pthread_t *, bool> >::const_iterator it;

  for (it = _threads.begin(); it != _threads.end(); ++it)
  {
    if (it->second)
    {
      it->second = false;
      //unlock the thread
      return (it->first);
    }
  }
}

void		pushThreadBack(pthread_t *thread)
{
  std::vector<std::pair<pthread_t *, bool> >::const_iterator it;

  for (it = _threads.begin(); it != _threads.end(); ++it)
  {
    if (it->first == thread)
    {
      it->second = true;
      // lock the thread
    }
  }  
}

bool		addNewThread()
{
  pthread_t *thread_tmp = new pthread_t;
  std::pair<pthread_t *, bool> tmp(thread_tmp, true);

  if (pthread_create(tmp.first, NULL, pendingFunc, NULL) != 0)
    throw ;
  _threads.push_back(tmp);
}

EThread::~EThread()
{
    while (!_threads.empty())
    {
      delete _threads.back();
      _threads.pop_back();
    }
}