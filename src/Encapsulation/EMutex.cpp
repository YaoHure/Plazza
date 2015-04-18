//
// EMutex.cpp for Plazza in /home/jibb/rendu/cpp_plazza/src/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jean-baptiste.gregoire@epitech.net>
//
// Started on  Fri Apr  17 21:43:46 2015 Jean-Baptiste Grégoire
// Last update Fri Apr  17 21:43:46 2015 Jean-Baptiste Grégoire
//

#include "EMutex.hh"

EMutex::EMutex()
{
  pthread_mutex_init(&_mutex, NULL);
}

int	EMutex::lock()
{
  return (pthread_mutex_lock(&_mutex));
}

int EMutex::trylock()
{
  return (pthread_mutex_trylock(&_mutex));
}

int EMutex::unlock()
{
  return (pthread_mutex_unlock(&_mutex));
}

pthread_mutex_t	*EMutex::getMutex()
{
  return (&_mutex);
}

EMutex::~EMutex()
{
  pthread_mutex_destroy(&_mutex);
}
