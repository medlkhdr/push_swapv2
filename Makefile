CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c parsing.c sorting.c stack_operations.c stack_utils.c utils.c big_sort.c
HEADER = push_swap.h
NAME = push_swap
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "maked push_swap"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "fcleaned"

re: fclean all
	@echo "remaked"

.PHONY: all clean fclean re