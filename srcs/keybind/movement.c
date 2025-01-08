/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:31:21 by levincen          #+#    #+#             */
/*   Updated: 2025/01/08 16:01:26 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_right(t_game *game)
{
	if (game->map->tab[game->map->pos_y][game->map->pos_x + 1] != '1')
	{
		if (game->map->tab[game->map->pos_y][game->map->pos_x + 1] == 'C')
		{
			game->map->tab[game->map->pos_y][game->map->pos_x + 1] = '0';
			game->map->collected++;
			ft_printf("Number of collected objects : %d\n", game->map->collected);
		}
		game->img->img = game->img->img_floor;
		game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		mlx_put_image_to_window(game->mlx, game->win, game->img->img, game->map->pos_x * TILE_WIDTH, game->map->pos_y * TILE_WIDTH);

		game->img->img = game->img->img_player;
		game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		mlx_put_image_to_window(game->mlx, game->win, game->img->img, (game->map->pos_x + 1) * TILE_WIDTH, game->map->pos_y * TILE_WIDTH);
		game->map->pos_x++;
		game->map->move_count++;
		ft_printf("Movement number : %d\n", game->map->move_count);
	}
}

void	move_left(t_game *game)
{
	if (game->map->copy[game->map->pos_y][game->map->pos_x - 1] != '1')
	{
		if (game->map->tab[game->map->pos_y][game->map->pos_x - 1] == 'C')
		{
			game->map->tab[game->map->pos_y][game->map->pos_x - 1] = '0';
			game->map->collected++;
			ft_printf("Number of collected objects : %d\n", game->map->collected);
		}
		game->img->img = game->img->img_floor;
		game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		mlx_put_image_to_window(game->mlx, game->win, game->img->img, game->map->pos_x * TILE_WIDTH, game->map->pos_y * TILE_WIDTH);

		game->img->img = game->img->img_player;
		game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		mlx_put_image_to_window(game->mlx, game->win, game->img->img, (game->map->pos_x - 1) * TILE_WIDTH, game->map->pos_y * TILE_WIDTH);
		game->map->pos_x--;
		game->map->move_count++;
		ft_printf("Movement number : %d\n", game->map->move_count);
	}
}

void	move_up(t_game *game)
{
	if (game->map->tab[game->map->pos_y + 1][game->map->pos_x] != '1')
	{
		if (game->map->tab[game->map->pos_y + 1][game->map->pos_x] == 'C')
		{
			game->map->tab[game->map->pos_y + 1][game->map->pos_x] = '0';
			game->map->collected++;
			ft_printf("Number of collected objects : %d\n", game->map->collected);
		}
		game->img->img = game->img->img_floor;
		game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		mlx_put_image_to_window(game->mlx, game->win, game->img->img, game->map->pos_x * TILE_WIDTH, game->map->pos_y * TILE_WIDTH);

		game->img->img = game->img->img_player;
		game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		mlx_put_image_to_window(game->mlx, game->win, game->img->img, game->map->pos_x * TILE_WIDTH, (game->map->pos_y + 1)* TILE_WIDTH);
		game->map->pos_y++;
		game->map->move_count++;
		ft_printf("Movement number : %d\n", game->map->move_count);
	}
}

void	move_down(t_game *game)
{
	if (game->map->tab[game->map->pos_y - 1][game->map->pos_x] != '1')
	{
		if (game->map->tab[game->map->pos_y - 1][game->map->pos_x] == 'C')
		{
			game->map->tab[game->map->pos_y - 1][game->map->pos_x] = '0';
			game->map->collected++;
			ft_printf("Number of collected objects : %d\n", game->map->collected);
		}
		game->img->img = game->img->img_floor;
		game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		mlx_put_image_to_window(game->mlx, game->win, game->img->img, game->map->pos_x * TILE_WIDTH, game->map->pos_y * TILE_WIDTH);

		game->img->img = game->img->img_player;
		game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
		mlx_put_image_to_window(game->mlx, game->win, game->img->img, game->map->pos_x * TILE_WIDTH, (game->map->pos_y - 1)* TILE_WIDTH);
		game->map->pos_y--;
		game->map->move_count++;
		ft_printf("Movement number : %d\n", game->map->move_count);
	}
}
