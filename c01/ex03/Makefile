CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98
SANFLAG = -fsanitize=address

RM = rm
RMFLAG = -rf

NAME = violence

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
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