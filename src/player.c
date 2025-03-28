/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:07 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/18 15:45:15 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_player(void *param)
{
	t_game	*game;
	double	delta_time;

	delta_time = get_delta_time();
	game = param;
	update_frame(game, delta_time);
	render_player(game);
}

void	update_frame(t_game *game, double delta_time)
{
	game->player->frame_time += delta_time;
	if (game->player->frame_time >= game->player->frame_move_delay)
	{
		game->player->current_frame = (game->player->current_frame + 1)
			% game->player->total_frames;
		game->player->frame_time = 0;
	}
}

void	main_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	double	delta_time;

	game = param;
	delta_time = get_delta_time_again();
	set_hooks(keydata, game, delta_time);
}

void	set_hooks(mlx_key_data_t keydata, t_game *game, double delta_time)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		game->player->move_time = 0;
		game->player->move_time += delta_time;
		game->player->move_delay = 0.03;
		if ((game->player->move_time >= game->player->move_delay
				&& keydata.action == MLX_REPEAT) || keydata.action == MLX_PRESS)
		{
			if (keydata.key == MLX_KEY_ESCAPE)
				mlx_close_window(game->mlx);
			else if (keydata.key == MLX_KEY_UP)
				move_player(game, 0, -1, game->player);
			else if (keydata.key == MLX_KEY_DOWN)
				move_player(game, 0, 1, game->player);
			else if (keydata.key == MLX_KEY_LEFT)
				move_player(game, -1, 0, game->player);
			else if (keydata.key == MLX_KEY_RIGHT)
				move_player(game, 1, 0, game->player);
		}
	}
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
	{
		ft_handle_final_exit(game);
		return ;
	}
	else
		ft_handle_common_move(game, x, y);
	ft_printf("Moves: %d\n", game->map->moves);
}
