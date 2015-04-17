//
// Error.hpp for Plazza in /home/tran_0/rendu/cpp_plazza/includes
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Thu Mar 26 16:34:32 2015 David Tran
// Last update Fri Apr 17 21:41:11 2015 Hugo Prenat
//

#ifndef ERROR_HH_
# define ERROR_HH_

# include <exception>
# include <stdexcept>

class			PlazzaErrorException : public std::exception
{
public:
  PlazzaErrorException(std::string const &messa);
  ~PlazzaErrorException() throw() {}

public:
  const char		*what() const throw();

private:
  std::string const	_message;
};

class			PlazzaErrorRuntime : public std::runtime_error
{
public:
  PlazzaErrorRuntime(std::string const &messa);
  ~PlazzaErrorRuntime() throw() {}

public:
  const char		*what() const throw();

private:
  std::string const	_message;
};

class			PlazzaErrorArg : public std::invalid_argument
{
public:
  PlazzaErrorArg(std::string const &messa);
  ~PlazzaErrorArg() throw() {}

public:
  const char		*what() const throw();

private:
  std::string const	_message;
};

#endif // !ERROR_HH_
