/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:36:42 by levincen          #+#    #+#             */
/*   Updated: 2025/01/14 17:48:46 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_ennemy(t_game *game, int x, int y)
{
	game->img->img = game->img->img_ennemy;
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, x * TILE_WIDTH, y * TILE_WIDTH);
}

void	movement(t_game *game)
{
	int	x;
	int	y;

	x = 5;
	y = 5;

	if (game->map->tab[y - 1][x] != '1')
	{
		put_floor(game, x, y);
		put_ennemy(game, x, y - 1);
		y--;
		sleep(1);
	}
}
