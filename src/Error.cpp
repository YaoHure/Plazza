//
// Error.cpp for Plazza in /home/tran_0/rendu/cpp_plazza/includes
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Thu Mar 26 17:30:00 2015 David Tran
// Last update Fri Apr 17 21:53:03 2015 Hugo Prenat
//

#include "Error.hh"

PlazzaErrorException::PlazzaErrorException(std::string const &messa) : std::exception(),
								       _message(messa)
{}

const char*	PlazzaErrorException::what() const throw()
{
  return (_message.c_str());
}

PlazzaErrorRuntime::PlazzaErrorRuntime(std::string const &messa) : std::runtime_error(messa),
								   _message(messa)
{}

const char*	PlazzaErrorRuntime::what() const throw()
{
  return (_message.c_str());
}

PlazzaErrorArg::PlazzaErrorArg(std::string const &messa) : std::invalid_argument(messa),
							   _message(messa)
{}

const char*	PlazzaErrorArg::what() const throw()
{
  return (_message.c_str());
}
