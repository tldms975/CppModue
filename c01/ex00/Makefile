CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98

RM = rm
RMFLAG = -rf

NAME = zombie

SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAG) -c $^ -o $@

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $^ -o $@

clean : 
	$(RM) $(RMFLAG) $(OBJ)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

.PHONY: all clean fclean re