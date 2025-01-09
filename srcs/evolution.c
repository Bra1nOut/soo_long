/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:06:26 by levincen          #+#    #+#             */
/*   Updated: 2025/01/09 17:34:13 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	first_third(t_game	*game)
{
	int	total;
	int	pourcentage;
	int	seuil;
	int	width;
	int	height;

	total = game->map->c_count;
	pourcentage = 35;
	seuil = (total * pourcentage) / 100;
	if (game->map->collected >= seuil && game->map->tg == 0)
	{
		mlx_destroy_image(game->mlx, game->img->img_player);
		game->img->img_player = mlx_xpm_file_to_image(game->mlx,
				"./Assets/Prinplouf.xpm", &width, &height);
		game->map->tg++;
	}
}

void	second_third(t_game *game)
{
	int	total;
	int	pourcentage;
	int	seuil;
	int	width;
	int	height;

	total = game->map->c_count;
	pourcentage = 75;
	seuil = (total * pourcentage) / 100;
	if (game->map->collected >= seuil)
	{
		mlx_destroy_image(game->mlx, game->img->img_player);
		game->img->img_player = mlx_xpm_file_to_image(game->mlx,
				"./Assets/Pingoleon.xpm", &width, &height);
	}
}
