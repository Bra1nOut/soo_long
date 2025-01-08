/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:41:56 by levincen          #+#    #+#             */
/*   Updated: 2025/01/07 16:25:22 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	return_error_v2(char *error)
{
	ft_printf("Error: %s\n", error);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	*game = malloc(sizeof(t_game));

	int	i;

	argc = 2;
	i = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(&argv[1][i], ".ber", 4) != 0)
		return_error_v2("Invalid file\n");
	read_map(game, argv[1]);
	fill_map_malloc(game, argv[1]);
	check_map(game)
	;
	printf("Map print :\n");
	for (int i = 0; i < game->map->line_count; i++)
		printf("%s", game->map->tab[i]);

	printf("Map path test print :\n");
	for (int i = 0; i < game->map->line_count; i++)
		printf("%s", game->map->copy[i]);

	window_init(game);
	load_img(game);
	put_img(game);
	mlx_action(game);
	return (0);
}
