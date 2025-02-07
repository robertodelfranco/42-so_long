/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:07 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/06 18:50:21 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(void *param)
{
	t_game	*game;

	game = param;
	set_hooks(game);
	put_images_in_window(game);
}

void	set_hooks(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_player(game, 0, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_player(game, 0, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_player(game, -1, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
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
		game->map->moves++;
		game->map->c--;
		game->map->map[game->map->pos_y_e][game->map->pos_x_e] = 'N';
	}
	else if (game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] == 'C')
	{
		game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] = 'P';
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
		game->map->moves++;
		game->map->c--;
	}
	else if (game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] == 'N')
	{
		game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] = 'P';
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
		game->map->moves++;
		ft_putstr_fd("You won!\n", 1);
		ft_putstr_fd("Moves: ", 1);
		ft_printf("%d\n", game->map->moves);
	}
}
