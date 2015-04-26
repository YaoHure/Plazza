//
// EFork.cpp for EFork in /home/tran_0/rendu/cpp_plazza
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Sun Apr 26 07:57:44 2015 David Tran
// Last update Sun Apr 26 10:15:39 2015 David Tran
//

#include "EFork.hh"

EFork::EFork()
{

}

int	EFork::launch(void (*routine)(void *), void *args)
{
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      routine(args);
      exit(EXIT_SUCCESS);
    }
  return (0);
}

pid_t	EFork::getPid() const
{
  return (pid);
}

EFork::~EFork()
{

}

void	EFork::waitFork() const
{
  waitpid(pid, NULL, WNOHANG);
}


void		son_fork(void *args)
{
  reinterpret_cast<Reception *>(args)->createKitchen();
}
