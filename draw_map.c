/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:20:17 by levincen          #+#    #+#             */
/*   Updated: 2025/01/07 16:20:40 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_game *game)
{
	int	height;
	int	width;

	game->img->img_wall = mlx_xpm_file_to_image(game->mlx, "./Assets/Tree_wall.xpm", &width, &height);
	game->img->img_floor = mlx_xpm_file_to_image(game->mlx, "./Assets/Grass_floor.xpm", &width, &height);
	game->img->img_player = mlx_xpm_file_to_image(game->mlx, "./Assets/Tiplouf.xpm", &width, &height);
}

void	put_img(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->line_count)
	{
		while (x < game->map->len)
		{
			if (game->map->tab[y][x] == '1')
				game->img->img =game->img->img_wall;
			else if (game->map->tab[y][x] == '0')
				game->img->img = game->img->img_floor;
			else if (game->map->tab[y][x] == 'P')
				game->img->img = game->img->img_player;
			game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
			mlx_put_image_to_window(game->mlx, game->win, game->img->img, x * TILE_WIDTH, y * TILE_WIDTH);
			x++;
		}
		x = 0;
		y++;
	}
}
