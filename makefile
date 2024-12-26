# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:19:45 by tsukuru           #+#    #+#              #
#    Updated: 2024/12/24 14:33:34 by tsukuru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# LIBFT_DIR = libft
# LIBFT = ./libft/libft.a
# RM = rm -rf

# SRC = src/main.c \
#       src/utils.c \
#       src/ft_command.c \
#       libft/ft_atoi.c \
#       libft/ft_memmove.c \
#       libft/ft_putendl_fd.c \
#       libft/ft_strdup.c \
#       libft/ft_strjoin.c \
#       libft/ft_strlcpy.c \
#       libft/ft_strlen.c \
#       libft/ft_strncmp.c
# # SRCS = main.c ft_command.c ft_split.c utils.c
# OBJ = $(SRC:.c=.o)

# NAME = push_swap_program

# all: $(NAME)

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# $(NAME): $(LIBFT) $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

# $(OBJ): $(SRC)
# 	$(CC) $(CFLAGS) -c -I./$(LIBFT) $< -o $@

# clean:
# 	$(RM) src/*.o
# 	make -C $(LIBFT_DIR) clean

# fclean: clean
# 	$(RM) $(NAME)
# 	make -C $(LIBFT_DIR) fclean

# re: fclean all clean

# .PHONY: all clean fclean re

# .SILENT:


# **************************************************************************** #
#                                   Settings                                   #
# **************************************************************************** #

CC         = gcc
CFLAGS     = -Wall -Wextra -Werror
RM         = rm -rf

# --- libft に関する設定 ---
LIBFT_DIR  = libft
LIBFT      = $(LIBFT_DIR)/libft.a

# --- 出力ファイル名 ---
NAME       = push_swap_program

# **************************************************************************** #
#                                 Sources/Objs                                 #
# **************************************************************************** #

SRC = src/main.c \
      src/utils.c \
      src/ft_command.c \
      libft/ft_atoi.c \
      libft/ft_memmove.c \
      libft/ft_putendl_fd.c \
      libft/ft_strdup.c \
      libft/ft_strjoin.c \
      libft/ft_strlcpy.c \
      libft/ft_strlen.c \
      libft/ft_strncmp.c

OBJ = $(SRC:.c=.o)

# **************************************************************************** #
#                                   Targets                                    #
# **************************************************************************** #

all: $(NAME)

# --- libft を先にビルドする ---
$(LIBFT):
	make -C $(LIBFT_DIR)

# --- 最終的に push_swap_program を生成 ---
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft

# --- 個別に .c -> .o を生成するルール (パターンルール) ---
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

# --- 後片付け ---
clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
