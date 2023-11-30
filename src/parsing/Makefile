# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buntakansirikamonthip <buntakansirikamonth +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 01:20:50 by bsirikam          #+#    #+#              #
#    Updated: 2023/11/21 17:55:11 by buntakansirikamo ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parsing

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CPPFLAGS = -std=c++98

OBJS = $(SRCS:.c=.o)
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJS))
HEADER = ../../includes/parsing.h


RM = rm -rf
LIBFT_PATH = ../../lib/libft/
LIBFT_A = ../../lib/libft/libft.a

SRCS = main.c pass.c passing_utils1.c passing_utils2.c passing_utils3.c \
init_data1.c init_data2.c init_data3.c init_data4.c init_plane1.c \
init_plane2.c passing_utils4.c init_sphere1.c init_cylinder1.c

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

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