# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:19:45 by tsukuru           #+#    #+#              #
#    Updated: 2025/02/07 11:56:41 by tkomai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


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
NAME       = push_swap

# **************************************************************************** #
#                                 Sources/Objs                                 #
# **************************************************************************** #

SRC = src/main.c \
      src/utils_memory.c \
      src/utils_numbers.c \
      src/sort.c \
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
