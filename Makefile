# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 14:17:20 by aghergut          #+#    #+#              #
#    Updated: 2025/02/24 15:13:24 by aghergut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s
# COLORS USED

DARK_GREEN = \033[38;5;22m
GRAY = \033[0;90m
RED = \033[0;91m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET_COLOR = \033[0m

# PROGRAM NAME
NAME = so_long

# COMPILER
COMPILER = cc

# FLAGS
CFLAGS = -Wall -Wextra -Werror -fPIE
LIBFT_FLAGS = -Limport/libft -lft
MLX_FLAGS = -Limport/mlx -lmlx -lX11 -lXext

# MAKE IMPORTS
MAKE_LIBFT = make -s -C import/libft > /dev/null 2>&1
MAKE_MLX = make -s -C import/mlx > /dev/null 2>&1

LIBS = $(LIBFT_FLAGS) $(MLX_FLAGS)

# SOURCES FOLDER
SRCS = ./srcs/
# OBJECTS FOLDER
OBJS = objects/

MANDATORY = mandatory/
BONUS = bonus/

# SUBFOLDERS
GAME = game/
UTILS = utils/
MAP = map/

# SOURCES FILES
SRCS_MANDATORY =	$(SRCS)$(MANDATORY)$(GAME)$(MAP)ft_buildmap.c \
					$(SRCS)$(MANDATORY)$(GAME)$(MAP)ft_checkmap.c \
					$(SRCS)$(MANDATORY)$(GAME)$(MAP)ft_errormap.c \
					$(SRCS)$(MANDATORY)$(GAME)ft_checkbody.c \
					$(SRCS)$(MANDATORY)$(GAME)ft_checkfood.c \
					$(SRCS)$(MANDATORY)$(GAME)ft_checkgate.c \
					$(SRCS)$(MANDATORY)$(GAME)ft_checkwall.c \
					$(SRCS)$(MANDATORY)$(GAME)ft_glogic.c \
					$(SRCS)$(MANDATORY)$(GAME)ft_gw.c \
					$(SRCS)$(MANDATORY)$(GAME)ft_hooks.c \
					$(SRCS)$(MANDATORY)$(GAME)ft_moves.c \
					$(SRCS)$(MANDATORY)$(UTILS)ft_immutable.c \
					$(SRCS)$(MANDATORY)$(UTILS)ft_items.c \
					$(SRCS)$(MANDATORY)$(UTILS)ft_snake_body.c \
					$(SRCS)$(MANDATORY)$(UTILS)ft_utils.c \
					$(SRCS)$(MANDATORY)$(UTILS)ft_freegame.c \
					$(SRCS)$(MANDATORY)$(UTILS)ft_freeitems.c \
					$(SRCS)$(MANDATORY)$(UTILS)ft_freestart.c \
					$(SRCS)$(MANDATORY)so_long.c

SRCS_BONUS =	$(SRCS)$(BONUS)$(GAME)$(MAP)ft_buildmap_bonus.c \
				$(SRCS)$(BONUS)$(GAME)$(MAP)ft_checkmap_bonus.c \
				$(SRCS)$(BONUS)$(GAME)$(MAP)ft_errormap_bonus.c \
				$(SRCS)$(BONUS)$(GAME)ft_checkbody_bonus.c \
				$(SRCS)$(BONUS)$(GAME)ft_checkfood_bonus.c \
				$(SRCS)$(BONUS)$(GAME)ft_checkgate_bonus.c \
				$(SRCS)$(BONUS)$(GAME)ft_checkenemy_bonus.c \
				$(SRCS)$(BONUS)$(GAME)ft_checkwall_bonus.c \
				$(SRCS)$(BONUS)$(GAME)ft_glogic_bonus.c \
				$(SRCS)$(BONUS)$(GAME)ft_gw_bonus.c \
				$(SRCS)$(BONUS)$(GAME)ft_hooks_bonus.c \
				$(SRCS)$(BONUS)$(GAME)ft_moves_bonus.c \
				$(SRCS)$(BONUS)$(UTILS)ft_freegame_bonus.c \
				$(SRCS)$(BONUS)$(UTILS)ft_freeitems_bonus.c \
				$(SRCS)$(BONUS)$(UTILS)ft_freestart_bonus.c \
				$(SRCS)$(BONUS)$(UTILS)ft_utils_bonus.c \
				$(SRCS)$(BONUS)$(UTILS)ft_immutable_bonus.c \
				$(SRCS)$(BONUS)$(UTILS)ft_items_bonus.c \
				$(SRCS)$(BONUS)$(UTILS)ft_snake_body_bonus.c \
				$(SRCS)$(BONUS)so_long_bonus.c

# MANDATORY OBJECTS
OBJS_MANDATORY = $(SRCS_MANDATORY:%.c=$(OBJS)%.o)
# BONUS OBJECTS
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJS)%.o)
				

# HEADER FILES INCLUDES
INCLUDES = -Iimport/mlx -Iimport/libft -I include

# FIRST TO BE EXECUTED
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

$(OBJS)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# RULES OF THE PROGRAM
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
	@rm -Rf $(OBJS)
	@make clean -s -C import/libft > /dev/null 2>&1
	@make clean -s -C import/mlx > /dev/null 2>&1
	@echo "so_long project successfully cleaned!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C import/libft > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re bonus

