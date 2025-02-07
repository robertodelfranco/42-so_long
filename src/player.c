/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:07 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/07 18:56:13 by rdel-fra         ###   ########.fr       */
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
		ft_handle_last_collectable(game, move_x, move_y);
	else if (game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] == 'C')
		ft_handle_collectable(game, move_x, move_y);
	else if (game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] == 'E')
		ft_handle_exit(game, move_x, move_y);
	else if (game->map->map[game->player->pos_y + move_y][game->player->pos_x + move_x] == 'N')
		ft_handle_final_exit(game, move_x, move_y);
	else
		ft_handle_common_move(game, move_x, move_y);
	ft_printf("Moves: %d\n", game->map->moves);
}
