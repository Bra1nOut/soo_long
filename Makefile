
NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
RM = rm -rf
LIBFT = libft/libft/libft.a
MLX_FLAGS = -L./minilibx-linux -lmlx -lbsd -lXext -lX11 -lm
LIBFT_FLAGS = -L./libft/libft -lft
SRCS =	srcs/main.c\
		srcs/window/window.c\
		srcs/maping/parsing.c\
		srcs/maping/map_checker.c\
		srcs/maping/map_checker2.c\
		srcs/maping/pathfinding.c\
		srcs/maping/draw_map.c\
		srcs/keybind/keybind.c\
		srcs/keybind/movement.c\

SRCS_BONUS = $(SRCS) \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

TARGET = $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(LIBFT):
	make -C libft/libft

.c.o:
	cc $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	make -C libft/libft re

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

.PHONY: all clean fclean re


