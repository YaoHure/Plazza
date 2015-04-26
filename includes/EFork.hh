//
// EFork.hh for EFork in /home/tran_0/rendu/cpp_plazza
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Sun Apr 26 07:43:28 2015 David Tran
// Last update Sun Apr 26 10:31:31 2015 David Tran
//

#ifndef EFORK_HH_
# define EFORK_HH_

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

void	son_fork(void *);

class	EFork
{
public:
  EFork();
  ~EFork();
public:
  int		launch(void (*routine)(void *), void *args);
  pid_t		getPid() const;
  void		waitFork() const;
private:
  pid_t		pid;
};

# include "Reception.hh"

#endif //EFORK_HH_
