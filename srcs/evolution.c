/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:06:26 by levincen          #+#    #+#             */
/*   Updated: 2025/01/14 17:35:12 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_evolving_piplup(t_game *game)
{
	int	width;
	int	height;

		game->img->img_player = mlx_xpm_file_to_image(game->mlx,
			"./Assets/Transition_Tiplouf.xpm", &width, &height);
		put_player(game, game->map->pos_x, game->map->pos_y);
		usleep(100000);
		mlx_destroy_image(game->mlx, game->img->img_player);
}

void	is_evolving_prinplup(t_game *game)
{
	int	width;
	int	height;

		game->img->img_player = mlx_xpm_file_to_image(game->mlx,
			"./Assets/Transition_Prinplouf.xpm", &width, &height);
		put_player(game, game->map->pos_x, game->map->pos_y);
		usleep(100000);
		mlx_destroy_image(game->mlx, game->img->img_player);
}

void	is_evolving_pingoleon(t_game *game)
{
	int	width;
	int	height;

		game->img->img_player = mlx_xpm_file_to_image(game->mlx,
			"./Assets/Transition_Pingoleon.xpm", &width, &height);
		put_player(game, game->map->pos_x, game->map->pos_y);
		usleep(100000);
		mlx_destroy_image(game->mlx, game->img->img_player);

}

void	tricky_evolving_prinplup(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->img_player);
	is_evolving_piplup(game);
	is_evolving_prinplup(game);
	is_evolving_piplup(game);
	is_evolving_prinplup(game);
	is_evolving_piplup(game);
	is_evolving_prinplup(game);
	printf("CHECK 4 %d\n", game->map->evolving);
	if (game->map->evolving == true)
		game->map->evolving = false;
}

void	tricky_evolving_pingoleon(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->img_player);
	is_evolving_prinplup(game);
	is_evolving_pingoleon(game);
	is_evolving_prinplup(game);
	is_evolving_pingoleon(game);
	is_evolving_prinplup(game);
	is_evolving_pingoleon(game);
}

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
		printf("right before evolving :%d\n", game->map->evolving);
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

void	test_first_third(t_game	*game)
{
	int	total;
	int	pourcentage;
	int	seuil;

	total = game->map->c_count - 1;
	pourcentage = 35;
	seuil = (total * pourcentage) / 100;
	if (game->map->collected >= seuil && game->map->tg == 0)
	{
		game->map->evolving = true;
	}
}
