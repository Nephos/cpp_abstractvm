NAME		= 	avm

SRC		=  	main.cpp

OBJ		=	$(SRC:.cpp=.o)

CFLAGS		+= 	-W -Wall -Werror

RM		= 	rm -f

CC		= 	g++

%.o: %.c
		@printf "[\033[0;32mdone\033[0m] % 33s\n" $<
		@$(CC) -c -o $@ $< $(CFLAGS)

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME)

clean:
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ)
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
