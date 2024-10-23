CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
DIR = main/
SRCS =		$(DIR)push_swap.c			\
			$(DIR)utils_algo.c			\
			$(DIR)utils_algo_2.c		\
			$(DIR)utils_algo_3.c		\
			$(DIR)utils_instructions.c	\
			$(DIR)utils_lists.c			\
			$(DIR)utils_other.c			\
			$(DIR)utils_setup.c			\
			$(DIR)utils_setup_2.c		\
			$(DIR)utils_split.c			\
			$(DIR)utils_strings.c		\
			$(DIR)utils_strings_2.c
OBJS = $(SRCS:.c=.o)
BONUSNAME = checker
BONUSDIR = bonus/
BONUSSRCS =	$(BONUSDIR)checker.c				\
			$(BONUSDIR)get_next_line.c			\
			$(BONUSDIR)get_next_line_utils.c	\
			$(BONUSDIR)utils_algo.c				\
			$(BONUSDIR)utils_instructions.c		\
			$(BONUSDIR)utils_lists.c			\
			$(BONUSDIR)utils_other.c			\
			$(BONUSDIR)utils_setup.c			\
			$(BONUSDIR)utils_setup_2.c			\
			$(BONUSDIR)utils_split.c			\
			$(BONUSDIR)utils_strings.c			\
			$(BONUSDIR)utils_strings_2.c
BONUSOBJS = $(BONUSSRCS:.c=.o)
all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUSNAME)

$(BONUSNAME):
	$(CC) $(FLAGS) $(BONUSSRCS) -o $@

bonusclean:
	rm -f $(BONUSOBJS)

bonusfclean: bonusclean
	rm -f $(BONUSNAME)

bonusre: bonusfclean bonus