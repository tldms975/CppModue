CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= exe_ex00

SRCS	= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS	= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(FLAGS) $^ -o $@

%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
