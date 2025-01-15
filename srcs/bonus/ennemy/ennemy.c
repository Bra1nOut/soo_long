/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:36:42 by levincen          #+#    #+#             */
/*   Updated: 2025/01/15 17:14:21 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"


void	put_ennemy(t_game *game, int x, int y)
{
	game->img->img = game->img->img_ennemy;
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, x * TILE_WIDTH, y * TILE_WIDTH);
}

void	check_a(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	game->map->p_count = 0;
	while (++j < game->map->line_count)
	{
		i = -1;
		while (++i < game->map->len)
		{
			if (game->map->tab[j][i] == 'A')
			{
				if (game->map->a_count == 0)
				{
					game->map->ennemy_pos_y = j;
					game->map->ennemy_pos_x = i;
				}
				game->map->p_count++;
				if (game->map->a_count > 1)
					return_error(game, "Multiple 'A' found");
			}
		}
	}
}

void	movement(t_game *game)
{
	if (game->map->tab[game->map->ennemy_pos_y - 1][game->map->ennemy_pos_x] != '1')
	{
		put_floor(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y);
		put_ennemy(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y - 1);
		game->map->ennemy_pos_y--;
		sleep(1);
	}
}
