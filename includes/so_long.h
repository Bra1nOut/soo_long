/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:39:59 by levincen          #+#    #+#             */
/*   Updated: 2025/01/08 15:59:40 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>

#  define red 0x00FF0000
#  define green 0x0000FF00
#  define blue 0x000000FF
#  define TILE_WIDTH 100
#  define TILE_HEIGHT 100

typedef struct	s_image {
	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_player;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_map
{
	char	**tab;
	char	**copy;
	int		line_count;
	int		len;
	int		e_count;
	int		p_count;
	int		c_count;
	int		move_count;
	int		pos_x;
	int		pos_y;
	int		collected;
}	t_map;

typedef struct	s_game{
	void	*mlx;
	void	*win;
	int		count_click;
	t_image	*img;
	t_map	*map;
}				t_game;

void	my_mlx_pixel_put(t_image *data, int x, int y);
void	window_init(t_game *game);
void	free_map(t_game *game);
int		win_close(t_game *game);

void	return_error(t_game *game, char *error);

//Parsing and map checker
void	fill_map_malloc(t_game *game, char *argv);
void	read_map(t_game *game, char *argv);
void	check_up_n_down(t_game *game);
void	check_left_n_right(t_game *game);
void	check_E(t_game *game);
void	check_P(t_game *game);
void	check_C(t_game *game);
void	check_other(t_game *game);
void	check_map(t_game *game);
void	re_check_E(t_game *game);
void	re_check_E(t_game *game);
void	pathfinding(t_game *game);

//Map drawing
void	load_img(t_game *game);
void	draw_map(t_game *game);

//Keybind
int		print_bozo();
int		keybind(int keycode, t_game *game);
void	mlx_action(t_game *game);

//Movements
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);


#endif
