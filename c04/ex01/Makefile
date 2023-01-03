CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98
SANFLAG = -g3 -fsanitize=address

NAME = leaktest

SRC = main.cpp \
			Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongCat.cpp \
			WrongAnimal.cpp \
			Brain.cpp
			
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $(SANFLAG) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re