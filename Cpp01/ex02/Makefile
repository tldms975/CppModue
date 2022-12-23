CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= ex02.exe

SRCS	= main.cpp
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
