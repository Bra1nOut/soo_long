
NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
RM = rm -rf
LIBFT = libft/libft.a
MLX_FLAGS = -L./minilibx-linux -lmlx -lbsd -lXext -lX11 -lm
LIBFT_FLAGS = -L./libft -lft
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[38;5;153m
NC = \033[0m
SRCS =	srcs/main.c\
		srcs/finish.c\
		srcs/mandatory/window/window.c\
		srcs/mandatory/maping/parsing.c\
		srcs/mandatory/maping/map_checker.c\
		srcs/mandatory/maping/map_checker2.c\
		srcs/mandatory/maping/pathfinding.c\
		srcs/mandatory/maping/draw_map.c\
		srcs/mandatory/keybind/keybind.c\
		srcs/mandatory/keybind/movement.c\
		srcs/evolution.c\
		srcs/ennemy.c\


SRCS_BONUS = $(SRCS) \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

TARGET = $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(RED)\e[1m┌─────$(NAME)────────────────────────────────────┐\e"
	@echo "││$(BLUE)		Compiling $(NAME) ⏳		 $(RED)│"
	@echo "\e[1m└────────────────────────────────────────────────┘\e"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@echo "$(RED)\e[1m┌─────$(NAME)────────────────────────────────────┐\e"
	@echo "││$(GREEN)		\e[1mCompilation termine ✅\e		 $(RED) │"
	@echo "\e[1m└────────────────────────────────────────────────┘\e"

$(LIBFT):
	@make -s -C libft

.c.o:
	@if [ "$(TARGET)" = "$(NAME)" ] && [ ! -f .mandatory ]; then \
		touch .mandatory; \
	fi
	@cc $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
	@make -s -C libft re

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

mlx:
	@git clone https://github.com/42Paris/minilibx-linux
	@echo "$(RED)\e[1m┌─────mlx────────────────────────────────────────┐\e"
	@echo "││$(BLUE)		Compiling mlx ⏳		 $(RED)│"
	@echo "\e[1m└────────────────────────────────────────────────┘\e"
	@cd minilibx-linux && make -s
	@echo "$(RED)\e[1m┌─────mlx────────────────────────────────────────┐\e"
	@echo "││$(GREEN)		\e[1mCompilation termine ✅\e		 $(RED) │"
	@echo "\e[1m└────────────────────────────────────────────────┘\e"

.PHONY: all clean fclean re bonus mlx
