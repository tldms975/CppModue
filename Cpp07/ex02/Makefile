CXX		 = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DEPFLAGS = -MMD# -g -fsanitize=address
NAME	 = ex02.exe
DIR_SRC = src
DIR_INC = inc
DIR_BUILD = build

SRCS_ORG = main.cpp
SRCS	= $(addprefix $(DIR_SRC)/, $(SRCS_ORG))
OBJS	= $(patsubst %.cpp, $(DIR_BUILD)/%.o, $(SRCS_ORG))
DEPS	= $(patsubst %.cpp, $(DIR_BUILD)/%.d, $(SRCS_ORG))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -I $(DIR_INC) $^ -o $@

$(DIR_BUILD)/%.o : $(DIR_SRC)/%.cpp
	@mkdir  -p $(DIR_BUILD)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -I $(DIR_INC) -c $< -o $@

clean :
	$(RM) -rf $(DIR_BUILD)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

-include $(DEPS)
