# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 01:20:50 by bsirikam          #+#    #+#              #
#    Updated: 2023/10/19 10:09:34 by ksaelim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#===================================================#
#------------- Variables / Compile Flag ------------#
#===================================================#

NAME = miniRT

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft/
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

MLX_DIR = mlx/
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

INCLUDES_DIR = includes/
INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(INCLUDES_DIR)

OBJS = $(SRCS:.c=.o)
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJS))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

RM = rm -rf


SRCS = src/parse/utils.c

#===================================================#
#------------------- Define Target -----------------#
#===================================================#

all: $(NAME)

$(NAME): libft $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

libft:
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)

clean:
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft