/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:22:58 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/18 15:44:45 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_handle_exit(t_game *game, int x, int y)
{
	if (game->map->map[game->player->pos_y][game->player->pos_x] != '0')
		mlx_image_to_window(game->mlx, game->img->floor_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	if (game->map->map[game->player->pos_y][game->player->pos_x] == 'T')
		mlx_image_to_window(game->mlx, game->img->tree_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	else if (game->map->map[game->player->pos_y][game->player->pos_x] != 'E')
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	else
		mlx_image_to_window(game->mlx, game->img->exit_img,
			game->player->pos_x * TILE + 17, game->player->pos_y * TILE + 34);
	game->map->moves++;
	game->player->pos_x += x;
	game->player->pos_y += y;
}

void	ft_handle_final_exit(t_game *game)
{
	game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	mlx_image_to_window(game->mlx,
		game->img->floor_img, game->player->pos_x * TILE,
		game->player->pos_y * TILE);
	game->map->moves++;
	ft_printf("You finished the game with %d moves\n", game->map->moves);
	ft_printf("You won!\n");
	mlx_close_window(game->mlx);
	free_and_close(game);
}

void	ft_handle_common_move(t_game *game, int x, int y)
{
	if (game->map->map[game->player->pos_y][game->player->pos_x] == 'T')
		mlx_image_to_window(game->mlx, game->img->tree_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	else if (game->map->map[game->player->pos_y][game->player->pos_x] == 'C')
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	else if (game->map->map[game->player->pos_y][game->player->pos_x] == 'E')
		mlx_image_to_window(game->mlx, game->img->exit_img,
			game->player->pos_x * TILE + 17, game->player->pos_y * TILE + 34);
	game->map->moves++;
	game->player->pos_x += x;
	game->player->pos_y += y;
}

void	ft_handle_collectable(t_game *game, int x, int y)
{
	if (game->map->map[game->player->pos_y][game->player->pos_x] != '0')
		mlx_image_to_window(game->mlx, game->img->floor_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	if (game->map->map[game->player->pos_y][game->player->pos_x] == 'T')
		mlx_image_to_window(game->mlx, game->img->tree_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	else if (game->map->map[game->player->pos_y][game->player->pos_x] != 'E')
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	else
		mlx_image_to_window(game->mlx, game->img->exit_img,
			game->player->pos_x * TILE + 17, game->player->pos_y * TILE + 34);
	game->player->pos_x += x;
	game->player->pos_y += y;
	mlx_image_to_window(game->mlx, game->img->floor_img,
		game->player->pos_x * TILE, game->player->pos_y * TILE);
	game->map->moves++;
	game->map->c--;
}

void	ft_handle_last_collectable(t_game *game, int x, int y)
{
	if (game->map->map[game->player->pos_y][game->player->pos_x] != '0')
		mlx_image_to_window(game->mlx, game->img->floor_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	if (game->map->map[game->player->pos_y][game->player->pos_x] == 'T')
		mlx_image_to_window(game->mlx, game->img->tree_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	else if (game->map->map[game->player->pos_y][game->player->pos_x] != 'E')
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	else
		mlx_image_to_window(game->mlx, game->img->exit_img,
			game->player->pos_x * TILE + 17, game->player->pos_y * TILE + 34);
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
