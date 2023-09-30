# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 01:20:50 by bsirikam          #+#    #+#              #
#    Updated: 2023/10/01 01:26:41 by bsirikam         ###   ########.fr        #
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

SRCS = main.c
HEADER = miniRT.h

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re