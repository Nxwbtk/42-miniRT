# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 01:20:50 by bsirikam          #+#    #+#              #
#    Updated: 2023/10/28 20:08:25 by bsirikam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CPPFLAGS = -std=c++98

OBJS = $(SRCS:.c=.o)
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJS))

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

RM = rm -rf
LIBFT_PATH = libft/
LIBFT_A = libft/libft.a

SRCS = main.c check_input1.c
HEADER = miniRT.h

all: $(NAME)

$(NAME): libft $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_A)

libft:
	@make -C $(LIBFT_PATH) 1> /dev/null

clean:
	@$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean 1> /dev/null

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean 1> /dev/null

re: fclean all

.PHONY: all clean fclean re libft