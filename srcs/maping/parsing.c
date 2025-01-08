/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:51:47 by levincen          #+#    #+#             */
/*   Updated: 2025/01/08 15:47:14 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	read_map(t_game *game, char *argv)
{
	int		fd;
	char	*temp;

	fd = open(argv, O_RDONLY);
	game->map = malloc(sizeof(t_map));
	temp = get_next_line(fd);
	game->map->line_count = 0;
	if (temp)
		game->map->line_count = 1;
	while (temp)
	{
		if (game->map->line_count == 1)
			free(temp);
		temp = get_next_line(fd);
		if (!temp)
			break ;
		game->map->line_count++;
		free(temp);
	}
	close(fd);
}

void	fill_map_malloc(t_game *game, char *argv)
{
	int fd;
	int	i;
	char	*temp;
	game->map->tab = malloc(sizeof(char *) * (game->map->line_count));
	game->map->copy = malloc(sizeof(char *) * (game->map->line_count));
	if (!game->map->tab || !game->map->copy)
		return ;
	i = 0;
	fd = open(argv, O_RDONLY);
	temp = get_next_line(fd);
	while (i < game->map->line_count)
	{
		game->map->tab[i] = ft_strdup(temp);
		game->map->copy[i] = ft_strdup(temp);
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	game->map->len = ft_strlen(game->map->tab[0]) - 1;
	free(temp);
}
