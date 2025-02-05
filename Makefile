# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 20:22:13 by ckrasniq          #+#    #+#              #
#    Updated: 2025/02/05 20:45:13 by ckrasniq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c map.c map_utils.c key_hook.c utils.c load_png.c map_check.c

# Create obj directory path
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_REPO = https://github.com/ckrasniqi/libft_updated.git

MLX_DIR = MLX42
MLX_BUILD = mlx_build
MLX = $(MLX_BUILD)/libmlx42.a
MLX_FLAGS = -lmlx42 -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

# Create obj directory
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@make -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@mkdir -p $(MLX_BUILD)
	@cd $(MLX_DIR) && cmake -B ../$(MLX_BUILD) && cmake --build ../$(MLX_BUILD)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_BUILD) -lmlx42 $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLX_BUILD)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(LIBFT_DIR)
	@rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re