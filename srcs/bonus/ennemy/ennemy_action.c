/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:38:12 by levincen          #+#    #+#             */
/*   Updated: 2025/01/16 19:07:17 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	check_a(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	game->map->a_count = 0;
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
				game->map->a_count++;
				if (game->map->a_count > 1)
					return_error(game, "Multiple 'A' found");
			}
		}
	}
}

void	put_ennemy(t_game *game, int x, int y)
{
	game->img->img = game->img->img_ennemy;
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, x * TILE_WIDTH, y * TILE_WIDTH);
}

void	put_corpse(t_game *game, int x, int y)
{
	int	height;
	int	width;

	if (game->map->ennemy_power == -1)
	{
		mlx_destroy_image(game->mlx, game->img->img_ennemy);
		game->img->img_ennemy = mlx_xpm_file_to_image(game->mlx,
			"./Assets/Dead_Tortipousse.xpm", &width, &height);
	}
	else if (game->map->ennemy_power == -2)
	{
		mlx_destroy_image(game->mlx, game->img->img_ennemy);
		game->img->img_ennemy = mlx_xpm_file_to_image(game->mlx,
			"./Assets/Tortipousse_Boom2.xpm", &width, &height);
	}
	put_ennemy(game, x, y);
}

void	battle(t_game *game, int x, int y)
{
	if (game->map->player_power <= game->map->ennemy_power)
		die(game);
	if (game->map->player_power > game->map->ennemy_power)
	{
		if (game->map->player_power == 2)
			game->map->ennemy_power = -1;
		if (game->map->player_power == 3)
			game->map->ennemy_power = -2;
		put_corpse(game, x, y);
		game->map->tab[y][x] = 'A';
		ft_printf("HAHA TES MORTS GROS TORTIPOUSSE !! TIPLOUF EVO SUPREMACY !!!\n");
	}
}
