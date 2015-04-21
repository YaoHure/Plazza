//
// ECondVar.cpp for Plazza in /home/jibb/rendu/cpp_plazza/src/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Fri Apr  17 22:05:54 2015 Jean-Baptiste Grégoire
// Last update Fri Apr  17 22:05:54 2015 Jean-Baptiste Grégoire
//

#include "ECondVar.hh"

ECondVar::ECondVar()
{
  if (pthread_cond_init(&_cond, NULL) != 0)
    throw ;
}

void  ECondVar::wakeUp(enum Target)
{
  if (BROADCAST)
    pthread_cond_broadcast(&_cond);
  else
    pthread_cond_signal(&_cond);
}

void	ECondVar::sleep(int sec)
{
  if (sec)
  {
    struct timespec t = {sec, 0};

    pthread_cond_timedwait(&_cond, _mutex.getMutex(), &t);
  }
  else
    pthread_cond_wait(&_cond, _mutex.getMutex());
}

ECondVar::~ECondVar()
{
  if (pthread_cond_destroy(&_cond) != 0)
    throw ;
}