/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:22:58 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/07 18:48:17 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_exit(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->img->floor_img,
		game->player->pos_x * TILE, game->player->pos_y * TILE);
	if (game->map->map[game->player->pos_y][game->player->pos_x] == 'T')
		mlx_image_to_window(game->mlx, game->img->tree_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	else if (game->map->map[game->player->pos_y][game->player->pos_x] != 'E')
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	else
		mlx_image_to_window(game->mlx, game->img->exit_img,
			game->player->pos_x * TILE + 12, game->player->pos_y * TILE + 12);
	game->map->moves++;
	game->player->pos_x += x;
	game->player->pos_y += y;
}

void	ft_handle_final_exit(t_game *game, int x, int y)
{
	game->map->map[game->player->pos_y + y][game->player->pos_x + x] = 'P';
	game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	mlx_image_to_window(game->mlx,
		game->img->floor_img, game->player->pos_x * TILE,
		game->player->pos_y * TILE);
	game->map->moves++;
	game->player->pos_x += x;
	game->player->pos_y += y;
	ft_putstr_fd("Moves: ", 1);
	ft_printf("%d\n", game->map->moves);
	ft_putstr_fd("You won\n", 1);
	mlx_close_window(game->mlx);
}

void	ft_handle_common_move(t_game *game, int x, int y)
{
	game->map->map[game->player->pos_y + y][game->player->pos_x + x] = 'P';
	mlx_image_to_window(game->mlx, game->img->floor_img,
		game->player->pos_x * TILE, game->player->pos_y * TILE);
	if (game->map->map[game->player->pos_y][game->player->pos_x] == 'T')
		mlx_image_to_window(game->mlx, game->img->tree_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	else if (game->map->map[game->player->pos_y][game->player->pos_x] != 'E')
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	else
		mlx_image_to_window(game->mlx, game->img->exit_img,
			game->player->pos_x * TILE + 12, game->player->pos_y * TILE + 12);
	game->map->moves++;
	game->player->pos_x += x;
	game->player->pos_y += y;
}

void	ft_handle_collectable(t_game *game, int x, int y)
{
	game->map->map[game->player->pos_y + y][game->player->pos_x + x] = 'P';
	mlx_image_to_window(game->mlx, game->img->floor_img,
		game->player->pos_x * TILE, game->player->pos_y * TILE);
	if (game->map->map[game->player->pos_y][game->player->pos_x] == 'T')
		mlx_image_to_window(game->mlx, game->img->tree_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	else if (game->map->map[game->player->pos_y][game->player->pos_x] != 'E')
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	else
		mlx_image_to_window(game->mlx, game->img->exit_img,
			game->player->pos_x * TILE + 12, game->player->pos_y * TILE + 12);
	game->player->pos_x += x;
	game->player->pos_y += y;
	mlx_image_to_window(game->mlx, game->img->floor_img,
		game->player->pos_x * TILE, game->player->pos_y * TILE);
	game->map->moves++;
	game->map->c--;
}

void	ft_handle_last_collectable(t_game *game, int x, int y)
{
	game->map->map[game->player->pos_y + y][game->player->pos_x + x] = 'P';
	mlx_image_to_window(game->mlx, game->img->floor_img,
		game->player->pos_x * TILE, game->player->pos_y * TILE);
	if (game->map->map[game->player->pos_y][game->player->pos_x] == 'T')
		mlx_image_to_window(game->mlx, game->img->tree_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	else if (game->map->map[game->player->pos_y][game->player->pos_x] != 'E')
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	else
		mlx_image_to_window(game->mlx, game->img->exit_img,
			game->player->pos_x * TILE + 12, game->player->pos_y * TILE + 12);
	game->player->pos_x += x;
	game->player->pos_y += y;
	mlx_image_to_window(game->mlx, game->img->floor_img,
		game->player->pos_x * TILE, game->player->pos_y * TILE);
	game->map->moves++;
	game->map->c--;
	game->map->map[game->map->pos_y_e][game->map->pos_x_e] = 'N';
	mlx_image_to_window(game->mlx, game->img->final_exit_img,
		game->map->pos_x_e * TILE, game->map->pos_y_e * TILE);
}
