//
// EThread.cpp for Plazza in /home/jibb/rendu/cpp_plazza/src/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Sat Apr  18 11:58:53 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 26 10:33:04 2015 David Tran
//

#include "EThread.hh"

EThread::EThread() : _running(false)
{

}

int	EThread::launch(void *(*routine)(void *), void *args)
{
  _running = true;
  if (pthread_create(&_thread, NULL, routine, args) != 0)
  {
    _running = false;
    return (-1);
  }
  return (0);
}

int	EThread::waitThread()
{
  int	ret = pthread_join(_thread, NULL);
  _running = false;
  return (ret);
}

bool	EThread::is_running() const
{
  return (_running);
}

EThread::~EThread()
{

}
