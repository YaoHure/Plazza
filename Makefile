##
## Makefile for Plazza in /home/jibb/rendu/cpp_plazza
##
## Made by Jean-Baptiste Grégoire
## Login   <jibb@epitech.net>
##
## Started on  Tue Apr 14 09:31:37 2015 Jean-Baptiste Grégoire
## Last update Thu Apr 23 17:10:45 2015 Hugo Prenat
##

DEBUG		= 	yes

NAME		=	plazza

SRCDIR		=	src/

OBJDIR		=	obj/

SRC		=	$(SRCDIR)Cooker.cpp	\
			$(SRCDIR)Error.cpp	\
			$(SRCDIR)Reception.cpp	\
			$(SRCDIR)main.cpp	\
			$(SRCDIR)Kitchen.cpp	\
			$(SRCDIR)EMutex.cpp	\
			$(SRCDIR)ECondVar.cpp	\
			$(SRCDIR)EThread.cpp	\
			$(SRCDIR)NamedPipe.cpp	\
			$(SRCDIR)ThreadPool.cpp	\
			$(SRCDIR)Pizza.cpp	\
			$(SRCDIR)Ingredients.cpp

OBJ		=	$(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))

RM		=	rm -fr

CC		=	g++

INCLUDES	=	-I includes/

CPPFLAGS	=	-W -Wall -Wextra $(INCLUDES)

LDFLAGS		=	-lncurses -lpthread

ifeq ($(DEBUG),yes)

CPPFLAGS 	+= 	-g3

else

CPPFLAGS	+= 	-O3

endif

FIRST		:=	$(shell test -d $(OBJDIR) || mkdir $(OBJDIR))

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHNOY:		re fclean clean all
