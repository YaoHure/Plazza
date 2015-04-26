//
// EFork.cpp for EFork in /home/tran_0/rendu/cpp_plazza
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun Apr 26 07:57:44 2015 David Tran
// Last update Sun Apr 26 18:53:11 2015 Jean-Baptiste Grégoire
//

#include "EFork.hh"

EFork::EFork()
{
}

int	EFork::launch(void (*routine)(void *), void *args)
{
  if ((_pid = fork()) == -1)
    return (-1);
  if (_pid == 0)
    {
      routine(args);
      exit(EXIT_SUCCESS);
    }
  return (0);
}

pid_t	EFork::getPid() const
{
  return (_pid);
}

EFork::~EFork()
{

}

void	EFork::waitFork()
{
  waitpid(_pid, &_status, WNOHANG);
}

int	EFork::getStatus() const
{
  return (_status);
}

void		son_fork(void *args)
{
  reinterpret_cast<Reception *>(args)->createKitchen();
}
