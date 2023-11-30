# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 01:20:50 by bsirikam          #+#    #+#              #
#    Updated: 2023/11/30 18:45:44 by bsirikam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#===================================================#
#------------- Variables / Compile Flag ------------#
#===================================================#

NAME = miniRT

CC = gcc
CFLAGS = -Wall -Wextra -Werror

### lib directory ###
LIB_DIR = lib/

### libft flags ###
LIBFT_DIR = $(LIB_DIR)libft/
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

### mlx flags ###
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	MLX_DIR = $(LIB_DIR)mlx_linux/
	MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz
else
	MLX_DIR = $(LIB_DIR)mlx_mac/
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

### header ###
INCLUDES_DIR = includes/
INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(INCLUDES_DIR)

OBJS = $(SRCS:.c=.o)
OBJ_DIR = .obj
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJS))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

RM = rm -rf

SRC_DIR = src
SRCS = $(shell find $(SRC_DIR) -name '*.c')

#===================================================#
#------------------- Define Target -----------------#
#===================================================#

all: $(NAME)

$(NAME): cclib $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

cclib:
#	@make -C $(LIBFT_DIR)
#	@make -C $(MLX_DIR)

clean:
#	@make fclean -C $(LIBFT_DIR)
#	@make clean -C $(MLX_DIR)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft