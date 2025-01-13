# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 14:17:20 by aghergut          #+#    #+#              #
#    Updated: 2025/01/13 18:36:06 by aghergut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DARK_GREEN = \033[38;5;22m
GRAY = \033[0;90m
RED = \033[0;91m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET_COLOR = \033[0m

NAME = so_long

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror
LIBFT_FLAGS = -Limport/libft -lft
MLX_FLAGS = -Limport/mlx -lmlx -lX11 -lXext

MAKE_LIBFT = make -s -C import/libft > /dev/null 2>&1
MAKE_MLX = make -s -C import/mlx > /dev/null 2>&1

LIBS = $(LIBFT_FLAGS) $(MLX_FLAGS)

CHECKMAP_FOLDER = check_map/
BUILDS_FOLDER = builds/
INGAME_FOLDER = ingame/

SRCS1 = $(CHECKMAP_FOLDER)check_map.c \
		$(CHECKMAP_FOLDER)checker.c \
		$(CHECKMAP_FOLDER)return_error.c
SRCS2 = $(BUILDS_FOLDER)add_body.c \
		$(BUILDS_FOLDER)deploy_immutable.c \
		$(BUILDS_FOLDER)deploy_items.c \
		$(BUILDS_FOLDER)free_game.c \
		$(BUILDS_FOLDER)free_items.c \
		$(BUILDS_FOLDER)game_window.c \
		$(BUILDS_FOLDER)hooks.c \
		$(BUILDS_FOLDER)utils.c \
        $(BUILDS_FOLDER)dead_body.c
SRCS3 = $(INGAME_FOLDER)check_body.c \
		$(INGAME_FOLDER)check_enemy.c \
		$(INGAME_FOLDER)check_food.c \
		$(INGAME_FOLDER)check_gate.c \
		$(INGAME_FOLDER)check_wall.c \
		$(INGAME_FOLDER)moving_around.c
MAIN = so_long.c

OBJS_DIR_CHECKMAP = $(CHECKMAP_FOLDER)objs/
OBJS_DIR_BUILDS = $(BUILDS_FOLDER)objs/
OBJS_DIR_INGAME = $(INGAME_FOLDER)objs/
OBJS_DIR_MAIN = objs/

OBJS = $(SRCS1:$(CHECKMAP_FOLDER)%.c=$(OBJS_DIR_CHECKMAP)%.o) \
       $(SRCS2:$(BUILDS_FOLDER)%.c=$(OBJS_DIR_BUILDS)%.o) \
       $(SRCS3:$(INGAME_FOLDER)%.c=$(OBJS_DIR_INGAME)%.o) \
       $(MAIN:%.c=$(OBJS_DIR_MAIN)%.o)

INCLUDES = -Imlx -Ilibft -I.

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GRAY)Compiling so_long...$(RESET_COLOR)"
	@echo "$(YELLOW)Compiling libft...$(RESET_COLOR)"
	@$(MAKE_LIBFT)
	@echo "$(BLUE)Compiling mlx...$(RESET_COLOR)"
	@$(MAKE_MLX)
	@echo "$(MAGENTA)Linking...$(RESET_COLOR)"
	@$(COMPILER) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(RED)A little more patience...$(RESET_COLOR)"
	@sleep 2
	@echo "$(DARK_GREEN)so_long compiled successfully!$(RESET_COLOR)"	

$(OBJS_DIR_CHECKMAP)%.o: $(CHECKMAP_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_CHECKMAP)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJS_DIR_BUILDS)%.o: $(BUILDS_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_BUILDS)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJS_DIR_INGAME)%.o: $(INGAME_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_INGAME)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR_MAIN)%.o: %.c
	@mkdir -p $(OBJS_DIR_MAIN)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -Rf $(OBJS_DIR_CHECKMAP)
	@rm -Rf $(OBJS_DIR_BUILDS)
	@rm -Rf $(OBJS_DIR_INGAME)
	@rm -Rf $(OBJS_DIR_MAIN)
	@make clean -s -C import/libft > /dev/null 2>&1
	@make clean -s -C import/mlx > /dev/null 2>&1
	@echo "so_long project successfully cleaned!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C import/libft > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re

