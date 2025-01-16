/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:44:01 by levincen          #+#    #+#             */
/*   Updated: 2025/01/16 18:44:19 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

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
		tricky_evolving_prinplup(game);
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
	if (game->map->collected >= seuil && game->map->ftg == 0)
	{
		game->map->evolving = true;
		tricky_evolving_pingoleon(game);
		game->img->img_player = mlx_xpm_file_to_image(game->mlx,
				"./Assets/Pingoleon.xpm", &width, &height);
		game->map->ftg++;
		game->map->evolving = false;
	}
}
