/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:25:12 by levincen          #+#    #+#             */
/*   Updated: 2025/01/16 18:40:43 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

int	keybind(int keycode, t_game *game)
{
	if (game->map->evolving == false)
	{
		if (keycode == 65307)
			win_close(game);
		if (keycode == 100)
			move_right(game);
		if (keycode == 97)
			move_left(game);
		if (keycode == 119)
			move_down(game);
		if (keycode == 115)
			move_up(game);
	}
	return (0);
}

void	mlx_action(t_game *game)
{
	if (game->map->evolving == false)
		mlx_hook(game->win, KeyPress, KeyPressMask, keybind, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, win_close, game);
}
