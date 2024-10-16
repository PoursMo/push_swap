CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = *.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $@

clean:

fclean:
	rm -f $(NAME)

re: fclean all