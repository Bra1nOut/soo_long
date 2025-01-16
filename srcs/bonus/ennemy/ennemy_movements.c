/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:36:42 by levincen          #+#    #+#             */
/*   Updated: 2025/01/16 18:38:44 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	ennemy_move_up(t_game *game)
{
		put_floor(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y);
		put_ennemy(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y - 1);
		game->map->tab[game->map->ennemy_pos_y][game->map->ennemy_pos_x] = '0';
		game->map->tab[game->map->ennemy_pos_y - 1][game->map->ennemy_pos_x] = 'A';
		game->map->ennemy_pos_y--;
}

void	ennemy_move_down(t_game *game)
{
		put_floor(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y);
		put_ennemy(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y + 1);
		game->map->tab[game->map->ennemy_pos_y][game->map->ennemy_pos_x] = '0';
		game->map->tab[game->map->ennemy_pos_y + 1][game->map->ennemy_pos_x] = 'A';
		game->map->ennemy_pos_y++;
}

void	ennemy_move_right(t_game *game)
{
	put_floor(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y);
	put_ennemy(game, game->map->ennemy_pos_x + 1, game->map->ennemy_pos_y);
	game->map->tab[game->map->ennemy_pos_y][game->map->ennemy_pos_x] = '0';
	game->map->tab[game->map->ennemy_pos_y][game->map->ennemy_pos_x + 1] = 'A';
	game->map->ennemy_pos_x++;
}

void	ennemy_move_left(t_game *game)
{
	put_floor(game, game->map->ennemy_pos_x, game->map->ennemy_pos_y);
	put_ennemy(game, game->map->ennemy_pos_x - 1, game->map->ennemy_pos_y);
	game->map->tab[game->map->ennemy_pos_y][game->map->ennemy_pos_x] = '0';
	game->map->tab[game->map->ennemy_pos_y][game->map->ennemy_pos_x - 1] = 'A';
	game->map->ennemy_pos_x--;
}

int	ennemy_movement(t_game *game)
{
	if (game->map->tab[game->map->ennemy_pos_y + 1][game->map->ennemy_pos_x] != '1' && game->frame == 360000)
	{
		ennemy_move_down(game);
	}
	if (game->map->tab[game->map->ennemy_pos_y][game->map->ennemy_pos_x + 1] != '1' && game->frame == 270000)
	{
		ennemy_move_right(game);
	}
	if (game->map->tab[game->map->ennemy_pos_y - 1][game->map->ennemy_pos_x] != '1' && game->frame == 180000)
	{
		ennemy_move_up(game);
	}
	if (game->map->tab[game->map->ennemy_pos_y][game->map->ennemy_pos_x - 1] != '1' && game->frame == 90000)
	{
		ennemy_move_left(game);
	}
	return (0);
}
