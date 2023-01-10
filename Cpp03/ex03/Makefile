CXX		 = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
NAME	 = ex03.exe

SRCS	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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
