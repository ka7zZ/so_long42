# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 14:17:20 by aghergut          #+#    #+#              #
#    Updated: 2025/02/22 17:08:54 by aghergut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

# SOURCES FOLDERS
SRCS = ./srcs/

MANDATORY = mandatory/
BONUS = bonus/

# SUBFOLDERS
GAME = game/
UTILS = utils/
BUILDS = builds/
CHECKERS = checkers/
FREES = frees/
MAP = map/

# SOURCES FILES
SRCS_MANDATORY_GAME =	$(SRCS)$(MANDATORY)$(GAME)ft_glogic.c \
						$(SRCS)$(MANDATORY)$(GAME)ft_gw.c \
						$(SRCS)$(MANDATORY)$(GAME)ft_hooks.c \
						$(SRCS)$(MANDATORY)$(GAME)ft_moves.c
SRCS_MANDATORY_BUILDS =	$(SRCS)$(MANDATORY)$(UTILS)$(BUILDS)ft_immutable.c \
						$(SRCS)$(MANDATORY)$(UTILS)$(BUILDS)ft_items.c \
						$(SRCS)$(MANDATORY)$(UTILS)$(BUILDS)ft_snake_body.c
SRCS_MANDATORY_CHECKERS =	$(SRCS)$(MANDATORY)$(UTILS)$(CHECKERS)ft_checkbody.c \
							$(SRCS)$(MANDATORY)$(UTILS)$(CHECKERS)ft_checkfood.c \
							$(SRCS)$(MANDATORY)$(UTILS)$(CHECKERS)ft_checkgate.c \
							$(SRCS)$(MANDATORY)$(UTILS)$(CHECKERS)ft_checkwall.c
SRCS_MANDATORY_FREES =	$(SRCS)$(MANDATORY)$(UTILS)$(FREES)ft_freegame.c \
						$(SRCS)$(MANDATORY)$(UTILS)$(FREES)ft_freeitems.c \
						$(SRCS)$(MANDATORY)$(UTILS)$(FREES)ft_freestart.c
SRCS_MANDATORY_MAP =	$(SRCS)$(MANDATORY)$(UTILS)$(MAP)ft_buildmap.c \
						$(SRCS)$(MANDATORY)$(UTILS)$(MAP)ft_checkmap.c \
						$(SRCS)$(MANDATORY)$(UTILS)$(MAP)ft_errormap.c
SRCS_MANDATORY_UTILS =	$(SRCS)$(MANDATORY)$(UTILS)ft_utils.c
SRCS_MANDATORY_MAIN =	$(SRCS)$(MANDATORY)so_long.c

SRCS_BONUS_GAME =	$(SRCS)$(BONUS)$(GAME)ft_glogic_bonus.c \
						$(SRCS)$(BONUS)$(GAME)ft_gw_bonus.c \
						$(SRCS)$(BONUS)$(GAME)ft_hooks_bonus.c \
						$(SRCS)$(BONUS)$(GAME)ft_moves_bonus.c
SRCS_BONUS_BUILDS =	$(SRCS)$(BONUS)$(UTILS)$(BUILDS)ft_immutable_bonus.c \
						$(SRCS)$(BONUS)$(UTILS)$(BUILDS)ft_items_bonus.c \
						$(SRCS)$(BONUS)$(UTILS)$(BUILDS)ft_snake_body_bonus.c
SRCS_BONUS_CHECKERS =	$(SRCS)$(BONUS)$(UTILS)$(CHECKERS)ft_checkbody_bonus.c \
							$(SRCS)$(BONUS)$(UTILS)$(CHECKERS)ft_checkfood_bonus.c \
							$(SRCS)$(BONUS)$(UTILS)$(CHECKERS)ft_checkgate_bonus.c \
							$(SRCS)$(BONUS)$(UTILS)$(CHECKERS)ft_checkenemy_bonus.c \
							$(SRCS)$(BONUS)$(UTILS)$(CHECKERS)ft_checkwall_bonus.c
SRCS_BONUS_FREES =	$(SRCS)$(BONUS)$(UTILS)$(FREES)ft_freegame_bonus.c \
						$(SRCS)$(BONUS)$(UTILS)$(FREES)ft_freeitems_bonus.c \
						$(SRCS)$(BONUS)$(UTILS)$(FREES)ft_freestart_bonus.c
SRCS_BONUS_MAP =	$(SRCS)$(BONUS)$(UTILS)$(MAP)ft_buildmap_bonus.c \
						$(SRCS)$(BONUS)$(UTILS)$(MAP)ft_checkmap_bonus.c \
						$(SRCS)$(BONUS)$(UTILS)$(MAP)ft_errormap_bonus.c
SRCS_BONUS_UTILS =	$(SRCS)$(BONUS)$(UTILS)ft_utils_bonus.c
SRCS_BONUS_MAIN =	$(SRCS)$(BONUS)so_long_bonus.c

# FOLDERS OBJECTS
MANDATORY_OBJS = $(SRCS)$(MANDATORY)
BONUS_OBJS = $(SRCS)$(BONUS)

# SUBFODERS OBJECTS
GAME_OBJS = $(GAME)objects/
BUILDS_OBJS = $(UTILS)$(BUILDS)objects/
CHECKERS_OBJS = $(UTILS)$(CHECKERS)objects/
FREES_OBJS = $(UTILS)$(FREES)objects/
MAP_OBJS = $(UTILS)$(MAP)objects/

# MANDATORY OBJECTS
OBJS_MANDATORY = 	$(addprefix $(MANDATORY_OBJS)$(GAME_OBJS), $(notdir $(SRCS_MANDATORY_GAME:.c=.o))) \
					$(addprefix $(MANDATORY_OBJS)$(BUILDS_OBJS), $(notdir $(SRCS_MANDATORY_BUILDS:.c=.o))) \
					$(addprefix $(MANDATORY_OBJS)$(CHECKERS_OBJS), $(notdir $(SRCS_MANDATORY_CHECKERS:.c=.o))) \
					$(addprefix $(MANDATORY_OBJS)$(FREES_OBJS), $(notdir $(SRCS_MANDATORY_FREES:.c=.o))) \
					$(addprefix $(MANDATORY_OBJS)$(MAP_OBJS), $(notdir $(SRCS_MANDATORY_MAP:.c=.o))) \
					$(addprefix $(MANDATORY_OBJS)$(UTILS), $(notdir $(SRCS_MANDATORY_UTILS:.c=.o))) \
					$(addprefix $(MANDATORY_OBJS), $(notdir $(SRCS_MANDATORY_MAIN:.c=.o)))

# BONUS OBJECTS
OBJS_BONUS = 	$(addprefix $(BONUS_OBJS)$(GAME_OBJS), $(notdir $(SRCS_BONUS_GAME:.c=.o))) \
				$(addprefix $(BONUS_OBJS)$(BUILDS_OBJS), $(notdir $(SRCS_BONUS_BUILDS:.c=.o))) \
				$(addprefix $(BONUS_OBJS)$(CHECKERS_OBJS), $(notdir $(SRCS_BONUS_CHECKERS:.c=.o))) \
				$(addprefix $(BONUS_OBJS)$(FREES_OBJS), $(notdir $(SRCS_BONUS_FREES:.c=.o))) \
				$(addprefix $(BONUS_OBJS)$(MAP_OBJS), $(notdir $(SRCS_BONUS_MAP:.c=.o))) \
				$(addprefix $(BONUS_OBJS)$(UTILS), $(notdir $(SRCS_BONUS_UTILS:.c=.o))) \
				$(addprefix $(BONUS_OBJS), $(notdir $(SRCS_BONUS_MAIN:.c=.o)))


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

$(MANDATORY_OBJS)$(GAME_OBJS)%.o: $(SRCS)$(MANDATORY)$(GAME)%.c
	@mkdir -p $(MANDATORY_OBJS)$(GAME_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MANDATORY_OBJS)$(BUILDS_OBJS)%.o: $(SRCS)$(MANDATORY)$(UTILS)$(BUILDS)%.c
	@mkdir -p $(MANDATORY_OBJS)$(BUILDS_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MANDATORY_OBJS)$(CHECKERS_OBJS)%.o: $(SRCS)$(MANDATORY)$(UTILS)$(CHECKERS)%.c
	@mkdir -p $(MANDATORY_OBJS)$(CHECKERS_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MANDATORY_OBJS)$(FREES_OBJS)%.o: $(SRCS)$(MANDATORY)$(UTILS)$(FREES)%.c
	@mkdir -p $(MANDATORY_OBJS)$(FREES_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MANDATORY_OBJS)$(MAP_OBJS)%.o: $(SRCS)$(MANDATORY)$(UTILS)$(MAP)%.c
	@mkdir -p $(MANDATORY_OBJS)$(MAP_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MANDATORY_OBJS)$(UTILS)%.o: $(SRCS)$(MANDATORY)$(UTILS)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MANDATORY_OBJS)%.o: $(SRCS)$(MANDATORY)%.c
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


$(BONUS_OBJS)$(GAME_OBJS)%.o: $(SRCS)$(BONUS)$(GAME)%.c
	@mkdir -p $(BONUS_OBJS)$(GAME_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJS)$(BUILDS_OBJS)%.o: $(SRCS)$(BONUS)$(UTILS)$(BUILDS)%.c
	@mkdir -p $(BONUS_OBJS)$(BUILDS_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJS)$(CHECKERS_OBJS)%.o: $(SRCS)$(BONUS)$(UTILS)$(CHECKERS)%.c
	@mkdir -p $(BONUS_OBJS)$(CHECKERS_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJS)$(FREES_OBJS)%.o: $(SRCS)$(BONUS)$(UTILS)$(FREES)%.c
	@mkdir -p $(BONUS_OBJS)$(FREES_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJS)$(MAP_OBJS)%.o: $(SRCS)$(BONUS)$(UTILS)$(MAP)%.c
	@mkdir -p $(BONUS_OBJS)$(MAP_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJS)$(UTILS)%.o: $(SRCS)$(BONUS)$(UTILS)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJS)%.o: $(SRCS)$(BONUS)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -Rf $(MANDATORY_OBJS)$(GAME_OBJS) $(MANDATORY_OBJS)$(BUILDS_OBJS) $(MANDATORY_OBJS)$(CHECKERS_OBJS) 
	@rm -Rf $(MANDATORY_OBJS)$(FREES) $(MANDATORY_OBJS)$(MAP_OBJS) $(MANDATORY_OBJS)$(UTILS)*.o $(MANDATORY_OBJS)*.o
	@rm -Rf $(BONUS_OBJS)$(GAME_OBJS) $(BONUS_OBJS)$(BUILDS_OBJS) $(BONUS_OBJS)$(CHECKERS_OBJS) 
	@rm -Rf $(BONUS_OBJS)$(FREES) $(BONUS_OBJS)$(MAP_OBJS) $(BONUS_OBJS)$(UTILS)*.o $(BONUS_OBJS)*.o
	@make clean -s -C import/libft > /dev/null 2>&1
	@make clean -s -C import/mlx > /dev/null 2>&1
	@echo "so_long project successfully cleaned!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C import/libft > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re bonus

