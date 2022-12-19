# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 18:53:55 by jasong            #+#    #+#              #
#    Updated: 2022/07/07 16:50:52 by jasong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	@$(CXX) $(CXXFLAG) -c $^ -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAG) $^ -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re