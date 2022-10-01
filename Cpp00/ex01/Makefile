
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS = $(addsuffix .cpp, \
		main\
		PhoneBook\
		Contact)
OBJS = $(SRCS:.cpp=.o)

NAME = phonebook

all: $(NAME)

%.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
