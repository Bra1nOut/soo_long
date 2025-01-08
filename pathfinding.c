/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:56:30 by levincen          #+#    #+#             */
/*   Updated: 2025/01/06 10:58:23 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_map(t_game *game, int y, int x)
{
	if (x > 0 && y > 0 && x < game->map->len && y < game->map->line_count
			&& game->map->copy[y][x] != '1' && game->map->copy[y][x] != 'F')
	{
		game->map->copy[y][x] = 'F';
		flood_map(game, y + 1, x);
		flood_map(game, y - 1, x);
		flood_map(game, y, x + 1);
		flood_map(game, y, x - 1);
	}
}

void	re_check_E(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map->line_count)
	{
		while (i < game->map->len)
		{
			if (game->map->copy[j][i] == 'E')
				return_error(game, "No path to get to the exit");
			i++;
		}
		j++;
		i = 0;
	}
}

void	re_check_C(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map->line_count)
	{
		while (i < game->map->len)
		{
			if (game->map->copy[j][i] == 'C')
				return_error(game, "No path to get all the collectible(s)");
			i++;
		}
		j++;
		i = 0;
	}
}

void	pathfinding(t_game *game)
{
	flood_map(game, game->map->pos_y, game->map->pos_x);
	re_check_E(game);
	re_check_C(game);
	ft_printf("La map est valide\n");
}
