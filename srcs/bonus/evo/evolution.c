/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:06:26 by levincen          #+#    #+#             */
/*   Updated: 2025/01/16 18:44:11 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

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
	game->map->player_power = 2;
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
	game->map->player_power = 3;
}
