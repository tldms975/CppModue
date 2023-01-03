CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)

NAME = scavtrap

all : $(NAME)
.PHONY: all

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

clean :
	rm -f $(OBJ)
.PHONY: clean

fclean : clean
	rm -f $(NAME)
.PHONY: re

re: fclean all 
.PHONY: re
