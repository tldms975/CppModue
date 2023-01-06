CXX		 = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
NAME	 = ex00.exe

SRCS	= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS	= $(SRCS:.cpp=.o)
DEPS	= $(SRCS:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re

-include $(DEPS)