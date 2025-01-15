/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:31:21 by levincen          #+#    #+#             */
/*   Updated: 2025/01/15 17:14:28 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	move_right(t_game *game)
{
	if (game->map->tab[game->map->pos_y][game->map->pos_x + 1] != '1')
	{
		if (game->map->tab[game->map->pos_y][game->map->pos_x + 1] == 'C')
		{
			game->map->tab[game->map->pos_y][game->map->pos_x + 1] = '0';
			game->map->collected++;
			first_third(game);
			second_third(game);
			printf("CHECK 3 %d\n", game->map->evolving);

			ft_printf("Object(s) collected : %d\n", game->map->collected);
		}
		if (game->map->tab[game->map->pos_y][game->map->pos_x + 1] == 'E')
			finish(game);
		put_floor(game, game->map->pos_x, game->map->pos_y);
		put_player(game, game->map->pos_x + 1, game->map->pos_y);
		game->map->pos_x++;
		game->map->move_count++;
		if (game->map->tab[game->map->pos_y][game->map->pos_x - 1] == 'E')
			put_exit(game, game->map->pos_x - 1, game->map->pos_y);
		ft_printf("Movement number : %d\n", game->map->move_count);
	}
}

void	move_left(t_game *game)
{
	if (game->map->copy[game->map->pos_y][game->map->pos_x - 1] != '1')
	{
		if (game->map->tab[game->map->pos_y][game->map->pos_x - 1] == 'C')
		{
			game->map->tab[game->map->pos_y][game->map->pos_x - 1] = '0';
			game->map->collected++;
			first_third(game);
			second_third(game);
			ft_printf("Object(s) collected : %d\n", game->map->collected);
		}
		if (game->map->tab[game->map->pos_y][game->map->pos_x - 1] == 'E')
			finish(game);
		put_floor(game, game->map->pos_x, game->map->pos_y);
		put_player(game, game->map->pos_x - 1, game->map->pos_y);
		game->map->pos_x--;
		game->map->move_count++;
		if (game->map->tab[game->map->pos_y][game->map->pos_x + 1] == 'E')
			put_exit(game, game->map->pos_x + 1, game->map->pos_y);
		ft_printf("Movement number : %d\n", game->map->move_count);
	}
}

void	move_up(t_game *game)
{
	if (game->map->tab[game->map->pos_y + 1][game->map->pos_x] != '1')
	{
		if (game->map->tab[game->map->pos_y + 1][game->map->pos_x] == 'C')
		{
			game->map->tab[game->map->pos_y + 1][game->map->pos_x] = '0';
			game->map->collected++;
			first_third(game);
			second_third(game);
			ft_printf("Object(s) collected : %d\n", game->map->collected);
		}
		if (game->map->tab[game->map->pos_y + 1][game->map->pos_x] == 'E')
			finish(game);
		put_floor(game, game->map->pos_x, game->map->pos_y);
		put_player(game, game->map->pos_x, game->map->pos_y + 1);
		game->map->pos_y++;
		game->map->move_count++;
		if (game->map->tab[game->map->pos_y - 1][game->map->pos_x] == 'E')
			put_exit(game, game->map->pos_x, game->map->pos_y - 1);
		ft_printf("Movement number : %d\n", game->map->move_count);
	}
}

void	move_down(t_game *game)
{
	if (game->map->tab[game->map->pos_y - 1][game->map->pos_x] != '1')
	{
		if (game->map->tab[game->map->pos_y - 1][game->map->pos_x] == 'C')
		{
			game->map->tab[game->map->pos_y - 1][game->map->pos_x] = '0';
			game->map->collected++;
			first_third(game);
			second_third(game);
			ft_printf("Object(s) collected : %d\n", game->map->collected);
		}
		if (game->map->tab[game->map->pos_y - 1][game->map->pos_x] == 'E')
			finish(game);
		put_floor(game, game->map->pos_x, game->map->pos_y);
		put_player(game, game->map->pos_x, game->map->pos_y - 1);
		game->map->pos_y--;
		game->map->move_count++;
		if (game->map->tab[game->map->pos_y + 1][game->map->pos_x] == 'E')
			put_exit(game, game->map->pos_x, game->map->pos_y + 1);
		ft_printf("Movement number : %d\n", game->map->move_count);
	}
}
