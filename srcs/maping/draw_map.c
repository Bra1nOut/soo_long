/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:20:17 by levincen          #+#    #+#             */
/*   Updated: 2025/01/08 15:47:14 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_img(t_game *game)
{
	int	height;
	int	width;

	game->img->img_wall = mlx_xpm_file_to_image(game->mlx, "./Assets/Tree_wall.xpm", &width, &height);
	game->img->img_floor = mlx_xpm_file_to_image(game->mlx, "./Assets/Grass_floor.xpm", &width, &height);
	game->img->img_player = mlx_xpm_file_to_image(game->mlx, "./Assets/Tiplouf.xpm", &width, &height);
	game->img->img_collectible = mlx_xpm_file_to_image(game->mlx, "./Assets/Rare_Candy2.xpm", &width, &height);

}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	void	*image;

	x = 0;
	y = 0;
	while (y < game->map->line_count)
	{
		while (x < game->map->len)
		{
			if (game->map->tab[y][x] == '1')
				image = game->img->img_wall;
			else if (game->map->tab[y][x] == '0')
				image = game->img->img_floor;
			else if (game->map->tab[y][x] == 'C')
				image = game->img->img_collectible;
			else if (game->map->tab[y][x] == 'P')
				image = game->img->img_player;
			game->img->addr = mlx_get_data_addr(image, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
			mlx_put_image_to_window(game->mlx, game->win, image, x * TILE_WIDTH, y * TILE_WIDTH);
			x++;
		}
		x = 0;
		y++;
	}
}
