/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:41:56 by levincen          #+#    #+#             */
/*   Updated: 2025/01/16 18:52:45 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	int		i;
	t_game	*game = malloc(sizeof(t_game));

	if (argc == 2)
	{
		i = ft_strlen(argv[1]) - 4;
		if (ft_strncmp(&argv[1][i], ".ber", 4) != 0)
			return_error_v2("Invalid file\n");
		read_map(game, argv[1]);
		game->map->collected = 0;
		game->map->move_count = 0;
		game->map->tg = 0;
		game->map->ftg = 0;
		game->map->evolving = false;
		game->map->player_power = 1;
		game->map->ennemy_power = 1;
		game->frame = 0;
		fill_map_malloc(game, argv[1]);
		check_map(game);
		ft_printf("Number of collectible : %d\n", game->map->c_count);
		window_init(game);
		load_img(game);
		draw_map(game);
		finish(game);
		mlx_action(game);
		if (game->map->ennemy_power == 1)
			mlx_loop_hook(game->mlx, ft_loop, game);
		mlx_loop(game->mlx);
		return (0);
	}
	free(game);
	return (0);
}
