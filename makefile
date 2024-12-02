# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:19:45 by tsukuru           #+#    #+#              #
#    Updated: 2024/12/02 18:29:56 by tsukuru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf

SRCS = swap.c
SRC = $(addprefix ./src/, $(SRCS))
OBJ = $(SRC:.c=.o)

NAME = push_swap_program

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c -I./$(LIBFT) $< -o $@

clean:
	$(RM) src/*.o
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all clean

.PHONY: all clean fclean re

.SILENT:
