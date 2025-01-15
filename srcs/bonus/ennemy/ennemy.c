/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:36:42 by levincen          #+#    #+#             */
/*   Updated: 2025/01/15 18:21:24 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"


void	put_ennemy(t_game *game, int x, int y)
{
	game->img->img = game->img->img_ennemy;
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, x * TILE_WIDTH, y * TILE_WIDTH);
}

void	ennemy_move_up(t_game *game)
{
		put_floor(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y);
		put_ennemy(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y - 1);
		game->map->ennemy_pos_y--;
}

void	ennemy_move_down(t_game *game)
{
		put_floor(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y);
		put_ennemy(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y + 1);
		game->map->ennemy_pos_y++;
}

void	ennemy_move_right(t_game *game)
{
	put_floor(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y);
	put_ennemy(game, game->map->ennemy_pos_x + 1, game->map->ennemy_pos_y);
	game->map->ennemy_pos_x++;
}

void	ennemy_move_left(t_game *game)
{
	put_floor(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y);
	put_ennemy(game, game->map->ennemy_pos_x - 1, game->map->ennemy_pos_y);
	game->map->ennemy_pos_x--;
}

void	movement(t_game *game)
{
	if (game->map->tab[game->map->ennemy_pos_y + 1][game->map->ennemy_pos_x] != '1')
		ennemy_move_down(game);
	else if (game->map->tab[game->map->ennemy_pos_y][game->map->ennemy_pos_x + 1] != '1')
		ennemy_move_right(game);
	else if (game->map->tab[game->map->ennemy_pos_y - 1][game->map->ennemy_pos_x] != '1')
		ennemy_move_up(game);
	else if (game->map->tab[game->map->ennemy_pos_y][game->map->ennemy_pos_x - 1] != '1')
		ennemy_move_left(game);
}
