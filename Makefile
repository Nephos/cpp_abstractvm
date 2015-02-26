NAME		= 	avm

SRC		=  	main.cpp	\
			Chipset.cpp	\
			VirtualCPU.cpp	\
			Exceptions.cpp

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	+= 	-W -Wall -Wextra -g

RM		= 	rm -f

CC		= 	g++

%.o: %.cpp
		@printf "[\033[0;32mdone\033[0m] % 33s\n" $< | sed "s/ /./2g"
		@$(CC) -c -o $@ $< $(CXXFLAGS)

all:		$(NAME)

debug:		CXXFLAGS += -DDEBUG_MODE
debug:		re

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME)

clean:
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ) $< | sed "s/ /./2g"
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME) $< | sed "s/ /./2g"

re:		fclean all

.PHONY:		all clean fclean re debug
