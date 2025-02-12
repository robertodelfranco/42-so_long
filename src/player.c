/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:07 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/12 11:34:26 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(void *param)
{
	t_game	*game;

	game = param;
	mlx_key_hook(game->mlx, set_hooks, game);
	mlx_image_to_window(game->mlx, game->player->player_img,
		game->player->pos_x * TILE + 7, game->player->pos_y * TILE + 14);
}

void	set_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_clear_window(game->mlx);
	else if (keydata.key == MLX_KEY_UP)
		move_player(game, 0, -1, game->player);
	else if (keydata.key == MLX_KEY_DOWN)
		move_player(game, 0, 1, game->player);
	else if (keydata.key == MLX_KEY_LEFT)
		move_player(game, -1, 0, game->player);
	else if (keydata.key == MLX_KEY_RIGHT)
		move_player(game, 1, 0, game->player);
}

void	move_player(t_game *game, int x, int y, t_player *player)
{
	if (game->map->map[player->pos_y + y][player->pos_x + x] == '1')
		return ;
	if (game->map->map[player->pos_y + y][player->pos_x + x] == 'C'
			&& game->map->c == 1)
		ft_handle_last_collectable(game, x, y);
	else if (game->map->map[player->pos_y + y][player->pos_x + x] == 'T')
		ft_handle_tree(game, x, y);
	else if (game->map->map[player->pos_y + y][player->pos_x + x] == 'C')
		ft_handle_collectable(game, x, y);
	else if (game->map->map[player->pos_y + y][player->pos_x + x] == 'E')
		ft_handle_exit(game, x, y);
	else if (game->map->map[player->pos_y + y][player->pos_x + x] == 'N')
		ft_handle_final_exit(game, x, y);
	else
		ft_handle_common_move(game, x, y);
	ft_printf("Moves: %d\n", game->map->moves);
}
