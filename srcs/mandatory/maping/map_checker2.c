/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:57:49 by levincen          #+#    #+#             */
/*   Updated: 2025/01/09 13:08:45 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	valid_character(t_game *game, char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
		return_error(game, "Invalid character found");
}

void	return_error(t_game *game, char *error)
{
	ft_printf("Error: %s\n", error);
	free_map(game);
	free(game);
	exit(EXIT_FAILURE);
}

void	check_len(t_game *game)
{
	int	i;
	int	temp_len;

	i = 0;
	temp_len = 0;
	while (i < game->map->line_count)
	{
		temp_len = ft_strlen(game->map->tab[i]) - 1;
		if (temp_len != game->map->len)
			return_error(game, "Map size is not uniform");
		i++;
	}
}

void	check_other(t_game *game)
{
	check_e(game);
	check_p(game);
	check_c(game);
	if (game->map->p_count < 1 || game->map->e_count < 1)
		return_error(game, "One 'E' or/and 'P' is required");
	if (game->map->c_count < 1)
		return_error(game, "At least one 'C' is required");
}

void	check_map(t_game *game)
{
	if (game->map->len == game->map->line_count)
		return_error(game, "Map is a square");
	check_len(game);
	check_up_n_down(game);
	check_other(game);
	check_left_n_right(game);
	pathfinding(game);
}
