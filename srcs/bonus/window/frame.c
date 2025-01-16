/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:42:32 by levincen          #+#    #+#             */
/*   Updated: 2025/01/16 18:42:55 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

int	ft_frame(t_game *game)
{
	game->frame++;
	if (game->frame > 360000)
		game->frame = 0;
	return (game->frame);
}

int	ft_loop(t_game *game)
{
	if (game->map->ennemy_power == 1)
	{
		ennemy_movement(game);
		ft_frame(game);
	}
	return (0);
}
