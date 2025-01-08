/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:25:12 by levincen          #+#    #+#             */
/*   Updated: 2025/01/07 16:25:33 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_bozo()
{
	printf("%s\n", "Sacha gros bozo");
	return (1);
}

int	keybind(int keycode, t_game *game)
{
	// printf("%i\n", keycode);
	if (keycode == 65307)
		win_close(game);
	if (keycode == 98)
		print_bozo();
	return (0);
}

void	mlx_action(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	// mlx_put_image_to_window(game->mlx, game->win, game->img->img, x, y);
	mlx_hook(game->win, KeyPress, KeyPressMask, keybind, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, win_close, game);
	mlx_loop(game->mlx);
}
