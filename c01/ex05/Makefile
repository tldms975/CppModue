CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98

RM = rm
RMFLAG = -f

NAME = harl20

SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAG) -c $^ -o $@

clean :
	$(RM) $(RMFLAG) $(OBJ)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

.PHONY: all clear fclean re