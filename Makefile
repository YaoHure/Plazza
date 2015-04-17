##
## Makefile for Plazza in /home/jibb/rendu/cpp_plazza
##
## Made by Jean-Baptiste Grégoire
## Login   <jibb@epitech.net>
##
## Started on  Tue Apr 14 09:31:37 2015 Jean-Baptiste Grégoire
## Last update Fri Apr 17 23:17:33 2015 Hugo Prenat
##

DEBUG		= 	yes

NAME		=	plazza

SRCDIR		=	src/

OBJDIR		=	obj/

SRC		=	$(SRCDIR)Cooker.cpp	\
			$(SRCDIR)Error.cpp	\
			$(SRCDIR)Reception.cpp	\
			$(SRCDIR)main.cpp	\
			$(SRCDIR)Kitchen.cpp

OBJ		=	$(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))

RM		=	rm -fr

CC		=	g++

INCLUDES	=	-I includes/

CPPFLAGS	=	-W -Wall -Wextra $(INCLUDES)

ifeq ($(DEBUG),yes)

CPPFLAGS 	+= 	-g3

else

CPPFLAGS	+= 	-O3

endif

FIRST		:=	$(shell test -d $(OBJDIR) || mkdir $(OBJDIR))

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHNOY:		re fclean clean all
