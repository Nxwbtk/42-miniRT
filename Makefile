# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 01:20:50 by bsirikam          #+#    #+#              #
#    Updated: 2023/11/16 02:28:25 by bsirikam         ###   ########.fr        #
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

SRCS = main.c passing_utils1.c passing_utils2.c passing_utils3.c \
init_data1.c init_data2.c init_data3.c init_data4.c init_plane1.c \
init_plane2.c passing_utils4.c init_sphere1.c init_cylinder1.c
HEADER = miniRT.h

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