CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= ex04.exe

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)
ASSETS	= *.replace

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(FLAGS) $^ -o $@

%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	rm -f $(ASSETS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)
	rm -f $(ASSETS)

re : clean all

.PHONY : all clean fclean re
