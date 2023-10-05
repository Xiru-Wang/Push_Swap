RED=\033[1;31m
GREEN=\033[1;32m
RESET=\033[0m

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIB = push_swap.h
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(OBJS) was creared.\n$(RESET)"
	@echo "$(GREEN)$(NAME) was creared.\n$(RESET)"

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@
# 	@echo "$(GREEN)$@ was created.$(RESET)"

clean:
	rm -f $(OBJS)
	@echo "$(RED)$(OBJS) was deleted $(RESET)"

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)$(NAME) was deleted $(RESET)"

re:		fclean all

.PHONY: all clean fclean re
