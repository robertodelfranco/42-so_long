/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:07 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/07 18:14:14 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(void *param)
{
	t_game	*game;

	game = param;
	set_hooks(game);
	mlx_image_to_window(game->mlx, game->player->player_img, game->player->pos_x * TILE, game->player->pos_y * TILE);
}

void	set_hooks(t_game *game)
{
	if (mlx_is_key_down(game->mlx, 256))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, 265))
		move_player(game, 0, -1);
	if (mlx_is_key_down(game->mlx, 264))
		move_player(game, 0, 1);
	if (mlx_is_key_down(game->mlx, 263))
		move_player(game, -1, 0);
	if (mlx_is_key_down(game->mlx, 262))
		move_player(game, 1, 0);
}

void	move_player(t_game *game, int move_x, int move_y)
{
	if (game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] == '1')
		return ;
	if (game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] == 'C' && game->map->c == 1)
	{
		game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] = 'P';
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
		mlx_image_to_window(game->mlx, game->img->floor_img, game->player->pos_x * TILE, game->player->pos_y * TILE);
		game->player->pos_x += move_x;
		game->player->pos_y += move_y;
		game->map->moves++;
		game->map->c--;
		mlx_image_to_window(game->mlx, game->img->final_exit_img, game->map->pos_x_e * TILE, game->map->pos_y_e * TILE);
	}
	else if (game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] == 'C')
	{
		game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] = 'P';
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
		mlx_image_to_window(game->mlx, game->img->floor_img, game->player->pos_x * TILE, game->player->pos_y * TILE);
		game->player->pos_x += move_x;
		game->player->pos_y += move_y;
		game->map->moves++;
		game->map->c--;
	}
	else if (game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] == 'E')
	{
		game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] = 'P';
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
		mlx_image_to_window(game->mlx, game->img->floor_img, game->player->pos_x * TILE, game->player->pos_y * TILE);
		game->map->moves++;
		game->player->pos_x += move_x;
		game->player->pos_y += move_y;
		ft_putstr_fd("You won!\n", 1);
		ft_putstr_fd("Moves: ", 1);
		ft_printf("%d\n", game->map->moves);
		mlx_close_window(game->mlx);
	}
	else
	{
		game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] = 'P';
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
		mlx_image_to_window(game->mlx, game->img->floor_img, game->player->pos_x * TILE, game->player->pos_y * TILE);
		game->map->moves++;
		game->player->pos_x += move_x;
		game->player->pos_y += move_y;
	}
	ft_printf("Moves: %d\n", game->map->moves);
}
