/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:54:44 by levincen          #+#    #+#             */
/*   Updated: 2025/01/09 11:06:14 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_up_n_down(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->tab[0][i] && i < game->map->len)
	{
		if (game->map->tab[0][i] != '1')
			return_error(game, "Wall not fully closed in top row");
		i++;
	}
	i = 0;
	while (game->map->tab[game->map->line_count - 1][i] && i < game->map->len)
	{
		if (game->map->tab[game->map->line_count - 1][i] != '1')
			return_error(game, "Wall not fully closed in bottom row");
		i++;
	}
}

void	check_left_n_right(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->map->line_count && game->map->tab[j][0])
	{
		if (game->map->tab[j][0] != '1' && j < game->map->line_count)
			return_error(game, "Wall not fully closed on the left side");
		j++;
	}
	j = 0;
	while (j < game->map->line_count && game->map->tab[j][game->map->len - 1])
	{
		if (game->map->tab[j][game->map->len - 1] != '1'
			&& j < game->map->line_count)
			return_error(game, "Wall not fully closed on the right side");
		j++;
	}
}

void	check_e(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->map->e_count = 0;
	while (j < game->map->line_count)
	{
		while (i < game->map->len)
		{
			valid_character(game, game->map->tab[j][i]);
			if (game->map->tab[j][i] == 'E')
			{
				game->map->e_count++;
				if (game->map->e_count > 1)
					return_error(game, "Multiple 'E' found");
			}
			i++;
		}
		j++;
		i = 0;
	}
}

void	check_p(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	game->map->p_count = 0;
	while (++j < game->map->line_count)
	{
		i = -1;
		while (++i < game->map->len)
		{
			if (game->map->tab[j][i] == 'P')
			{
				if (game->map->p_count == 0)
				{
					game->map->pos_y = j;
					game->map->pos_x = i;
				}
				game->map->p_count++;
				if (game->map->p_count > 1)
					return_error(game, "Multiple 'P' found");
			}
		}
	}
}

void	check_c(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->map->c_count = 0;
	while (j < (game->map->line_count - 1))
	{
		while (i < game->map->len)
		{
			if (game->map->tab[j][i] == 'C')
				game->map->c_count++;
			i++;
		}
		j++;
		i = 0;
	}
}
