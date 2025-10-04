/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:07 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/18 16:20:01 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_player(void *param)
{
	t_game	*game;
	double	delta_time;

	delta_time = get_delta_time();
	game = param;
	if (game->game_win_flag == 1)
		return ;
	if (game->game_over_flag == 1)
	{
		update_dead(game, delta_time);
		if (game->player->current_frame == 4)
			game->game_over_flag = 2;
	}
	if (game->game_over_flag >= 1)
		return ;
	update_frame(game, delta_time);
	render_player(game);
	if (game->enemie->e > 0)
		update_enemy(game, delta_time);
	if (game->player->pos_x == game->enemie->pos_x
		&& game->player->pos_y == game->enemie->pos_y)
		ft_handle_enemie(game);
}

void	update_frame(t_game *game, double delta_time)
{
	game->player->frame_time += delta_time;
	if (game->player->frame_time >= game->player->frame_move_delay)
	{
		game->player->current_frame = (game->player->current_frame + 1)
			% game->player->total_frames;
		game->enemie->current_frame = (game->enemie->current_frame + 1)
			% game->enemie->total_frames;
		game->player->frame_time = 0;
	}
}

static void	move_player(t_game *game, double x, double y, t_player *player)
{
	char	*moves;
	char	*nb;

	if (game->map->map[(int)(player->pos_y + y)][(int)(player->pos_x + x)] == '1')
		return ;
	if (game->map->map[(int)(player->pos_y + y)][(int)(player->pos_x + x)] == 'C'
			&& game->map->c_now == 1)
		ft_handle_last_collectable(game, (player->pos_x + x), (player->pos_y + y));
	else if (game->map->map[(int)(player->pos_y + y)][(int)(player->pos_x + x)] == 'C')
		ft_handle_collectable(game, (player->pos_x + x), (player->pos_y + y));
	else if (game->map->map[(int)(player->pos_y + y)][(int)(player->pos_x + x)] == 'E')
		ft_handle_exit(game, (player->pos_x + x), (player->pos_y + y));
	else if (game->map->map[(int)(player->pos_y + y)][(int)(player->pos_x + x)] == 'N')
		ft_handle_final_exit(game);
	else
		ft_handle_common_move(game, (player->pos_x + x), (player->pos_y + y));
	nb = ft_itoa(game->map->moves);
	moves = ft_strjoin("Moves: ", nb);
	mlx_image_to_window(game->mlx, game->img->ribbon_img, 0, 0 + 2);
	mlx_put_string(game->mlx, moves, 46, 10);
	free(moves);
	free(nb);
}

static void	set_hooks(mlx_key_data_t keydata, t_game *game, double delta_time)
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
			else if (keydata.key == MLX_KEY_UP && game->game_over_flag == 0)
				move_player(game, 0, -0.5, game->player);
			else if (keydata.key == MLX_KEY_DOWN && game->game_over_flag == 0)
				move_player(game, 0, 0.5, game->player);
			else if (keydata.key == MLX_KEY_LEFT && game->game_over_flag == 0)
				move_player(game, -0.5, 0, game->player);
			else if (keydata.key == MLX_KEY_RIGHT && game->game_over_flag == 0)
				move_player(game, 0.5, 0, game->player);
		}
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
