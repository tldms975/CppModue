# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 18:53:55 by jasong            #+#    #+#              #
#    Updated: 2022/09/04 14:40:28 by jasong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

SRC = PhoneBook.cpp Contact.cpp main.cpp
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