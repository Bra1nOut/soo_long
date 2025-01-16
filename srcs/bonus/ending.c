/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:52:27 by levincen          #+#    #+#             */
/*   Updated: 2025/01/16 18:57:05 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	die(t_game *game)
{
	ft_printf("Tiplouf est mort, il n'est pas assez puissant. Tu as perdu.\n");
	free_map(game);
	free(game);
	exit(EXIT_FAILURE);
}

void	return_error(t_game *game, char *error)
{
	ft_printf("Error: %s\n", error);
	free_map(game);
	free(game);
	exit(EXIT_FAILURE);
}

void	return_error_v2(char *error)
{
	ft_printf("Error: %s\n", error);
	exit(EXIT_FAILURE);
}
