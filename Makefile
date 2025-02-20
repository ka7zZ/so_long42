# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 14:17:20 by aghergut          #+#    #+#              #
#    Updated: 2025/02/20 16:11:45 by aghergut         ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror -fPIE
LIBFT_FLAGS = -Limport/libft -lft
MLX_FLAGS = -Limport/mlx -lmlx -lX11 -lXext

MAKE_LIBFT = make -s -C import/libft > /dev/null 2>&1
MAKE_MLX = make -s -C import/mlx > /dev/null 2>&1

LIBS = $(LIBFT_FLAGS) $(MLX_FLAGS)

SRCS_FOLDER = $(SRCS_FOLDER)srcs/
MANDATORY_FOLDER = $(SRCS_FOLDER)mandatory/
BONUS_FOLDER = $(SRCS_FOLDER)bonus/


SRCS_UTILS =	$(UTILS_FOLDER)check_body.c \
				$(UTILS_FOLDER)check_food.c \
				$(UTILS_FOLDER)check_gate.c \
				$(UTILS_FOLDER)check_wall.c \
				$(UTILS_FOLDER)checkmap_error.c \
				$(UTILS_FOLDER)count_moves.c \
				$(UTILS_FOLDER)create_map.c \
				$(UTILS_FOLDER)deploy_immutable.c \
				$(UTILS_FOLDER)free_start.c \
				$(UTILS_FOLDER)snake_body.c \
				$(UTILS_FOLDER)utils.c
SRCS_MANDATORY = 	$(MANDATORY_FOLDER)check_map.c \
					$(MANDATORY_FOLDER)deploy_items.c \
					$(MANDATORY_FOLDER)free_game.c \
					$(MANDATORY_FOLDER)free_items.c \
					$(MANDATORY_FOLDER)game_logic.c \
					$(MANDATORY_FOLDER)hooks.c \
					$(MANDATORY_FOLDER)game_window.c \
					$(MANDATORY_FOLDER)so_long.c \
					$(SRCS_UTILS)
SRCS_BONUS =	$(BONUS_FOLDER)check_enemy_bonus.c \
				$(BONUS_FOLDER)check_map_bonus.c \
				$(BONUS_FOLDER)deploy_items_bonus.c \
				$(BONUS_FOLDER)free_game_bonus.c \
				$(BONUS_FOLDER)free_items_bonus.c \
				$(BONUS_FOLDER)game_logic_bonus.c \
				$(BONUS_FOLDER)game_window_bonus.c \
				$(BONUS_FOLDER)hooks_bonus.c \
				$(BONUS_FOLDER)so_long_bonus.c \
				$(SRCS_UTILS)

OBJSMAND_FOLDER = $(MANDATORY_FOLDER)/objects
OBJSBONUS_FOLDER = $(BONUS_FOLDER)/objects
OBJSUTI_FOLDER = $(UTILS_FOLDER)/objects

OBJS_MANDATORY = 	$(SRCS_MANDATORY:$(MANDATORY_FOLDER)%.c=$(OBJSMAND_FOLDER)%.o) \
	   				$(SRCS_UTILS:$(UTILS_FOLDER)%.c=$(OBJSUTI_FOLDER)%.o)

OBJS_BONUS =	$(SRCS_BONUS:$(BONUS_FOLDER)%.c=$(OBJSBONUS_FOLDER)%.o) \
	   			$(SRCS_UTILS:$(UTILS_FOLDER)%.c=$(OBJSUTI_FOLDER)%.o)


INCLUDES_IMPORTS = -Imlx -Ilibft -I.
INCLUDES = -I include/

all: $(NAME)

$(NAME): $(OBJS_MANDATORY)
	@echo "$(GRAY)Compiling so_long...$(RESET_COLOR)"
	@echo "$(YELLOW)Compiling libft...$(RESET_COLOR)"
	@$(MAKE_LIBFT)
	@echo "$(BLUE)Compiling mlx...$(RESET_COLOR)"
	@$(MAKE_MLX)
	@echo "$(MAGENTA)Linking...$(RESET_COLOR)"
	@$(COMPILER) $(CFLAGS) $(OBJS_MANDATORY) $(LIBS) -o $(NAME)
	@echo "$(RED)so_long compiled successfully!$(RESET_COLOR)"	

$(OBJSMAND_FOLDER)%.o: $(MANDATORY_FOLDER)%.c
	@mkdir -p $(OBJSMAND_FOLDER)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) $(INCLUDES_IMPORTS) -c $< -o $@

$(OBJSUTI_FOLDER)%.o: $(UTILS_FOLDER)%.C
	@mkdir -p $(OBJSUTI_FOLDER)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) $(INCLUDES_IMPORTS) -c $< -o $@

$(OBJSBONUS_FOLDER)%.o: $(BONUS_FOLDER)%.c
	@mkdir -p $(OBJSBONUS_FOLDER)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) $(INCLUDES_IMPORTS) -c $< -o $@

bonus: fclean $(OBJS_BONUS)
	@echo "$(GRAY)Compiling so_long with bonus...$(RESET_COLOR)"
	@echo "$(YELLOW)Compiling libft...$(RESET_COLOR)"
	@$(MAKE_LIBFT)
	@echo "$(BLUE)Compiling mlx...$(RESET_COLOR)"
	@$(MAKE_MLX)
	@echo "$(MAGENTA)Linking...$(RESET_COLOR)"
	@$(COMPILER) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $(NAME)
	@echo "$(RED)so_long compiled successfully!$(RESET_COLOR)"

clean:
	@rm -Rf $(OBJSMAND_FOLDER) $(OBJSUTI_FOLDER) $(OBJSBONUS_FOLDER)
	@make clean -s -C import/libft > /dev/null 2>&1
	@make clean -s -C import/mlx > /dev/null 2>&1
	@echo "so_long project successfully cleaned!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C import/libft > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re

