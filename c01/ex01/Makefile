CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98
SANFLAG = -fsanitize=address

RM = rm
RMFLAG = -rf

NAME = morebrainz

SRC = main.cpp Zombie.cpp zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAG) -c $^ -o $@

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) -g $(SANFLAG) $^ -o $@

clean : 
	$(RM) $(RMFLAG) $(OBJ)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

.PHONY: all clean fclean re