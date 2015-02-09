##
## Makefile for  in /home/poulet_a/rendu/cpp_abstractvm
##
## Made by Arthur Poulet
## Login   <poulet_a@epitech.net>
##
## Started on  Mon Feb  9 16:59:39 2015 Arthur Poulet
## Last update Mon Feb  9 17:03:02 2015 Arthur Poulet
##

RM	=	rm -f

CFLAGS  +=      -Wall -Wextra -Werror

NAME	=	avm

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		g++ $(SRCS) $(CFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
