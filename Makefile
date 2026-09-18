NAME := push_swap
BONUS_NAME := checker
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -Iincludes
RM := rm -f

COMMON_SRCS := src/input.c src/utils.c src/positions.c src/ft_command.c
PUSH_SRCS := src/main.c src/sort.c $(COMMON_SRCS)
BONUS_SRCS := src/checker_bonus.c $(COMMON_SRCS)
PUSH_OBJS := $(PUSH_SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PUSH_OBJS)
	$(CC) $(CFLAGS) $(PUSH_OBJS) -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $@

%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(PUSH_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
