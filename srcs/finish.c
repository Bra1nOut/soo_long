/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:31:13 by levincen          #+#    #+#             */
/*   Updated: 2025/01/09 10:59:40 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	finish(t_game *game)
{
	if (game->map->collected == game->map->c_count)
	{
		ft_printf("Vous avez gagne, bravo !\n");
		win_close(game);
		exit(0);
	}
}
