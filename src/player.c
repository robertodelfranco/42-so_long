/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:07 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/10 15:37:36 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(void *param)
{
	t_game	*game;

	game = param;
	mlx_key_hook(game->mlx, set_hooks, game);
	mlx_image_to_window(game->mlx, game->player->player_img, game->player->pos_x * TILE + 7, game->player->pos_y * TILE + 7);
}

void	set_hooks(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;

	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_UP)
			move_player(game, 0, -1);
		else if (keydata.key == MLX_KEY_DOWN)
			move_player(game, 0, 1);
		else if (keydata.key == MLX_KEY_LEFT)
			move_player(game, -1, 0);
		else if (keydata.key == MLX_KEY_RIGHT)
			move_player(game, 1, 0);	
	}
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
