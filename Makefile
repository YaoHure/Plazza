##
## Makefile for Plazza in /home/jibb/rendu/cpp_plazza
##
## Made by Jean-Baptiste Grégoire
## Login   <jibb@epitech.net>
##
## Started on  Tue Apr 14 09:31:37 2015 Jean-Baptiste Grégoire
## Last update Tue Apr 14 09:49:18 2015 Jean-Baptiste Grégoire
##

DEBUG		= 	no

NAME		=	plazza

SRC		=	src/main.cpp

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -f

CC		=	g++

INCLUDES	=	includes/

FOLDER_SRC	=	src/

CPPFLAGS	=	-W -Wall -Wextra -I $(INCLUDES)

ifeq ($(DEBUG),yes)

CPPFLAGS 	+= -g3

else

CPPFLAGS	+= -O3

endif

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHNOY:		re fclean clean all
