/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:09:52 by levincen          #+#    #+#             */
/*   Updated: 2025/01/08 18:43:04 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	my_mlx_pixel_put(t_image *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
}

void	window_init(t_game *game)
{
	game->count_click = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->len * TILE_WIDTH, game->map->line_count * TILE_HEIGHT, "so_long");
	game->img = malloc(sizeof(t_image));
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->line_count)
	{
		free(game->map->tab[i]);
		i++;
	}
	free(game->map->tab);
	i = 0;
	while (i < game->map->line_count)
	{
		free(game->map->copy[i]);
		i++;
	}
	free(game->map->copy);
	free(game->map);
}

void	free_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->img_floor);
	mlx_destroy_image(game->mlx, game->img->img_wall);
	mlx_destroy_image(game->mlx, game->img->img_collectible);
	mlx_destroy_image(game->mlx, game->img->img_player);
}

int	win_close(t_game *game)
{
	free_image(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game->img);
	free_map(game);
	exit(0);
}

