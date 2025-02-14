/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:58:20 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/14 20:51:37 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_enemie_animation(t_game *game)
{
	game->enemie->frames_text[0] = mlx_load_png("textures/goblin.png");
	game->enemie->frames_img[0] = mlx_texture_to_image(game->mlx,
			game->enemie->frames_text[0]);
	game->enemie->frames_text[1] = mlx_load_png("textures/goblin_2.png");
	game->enemie->frames_img[1] = mlx_texture_to_image(game->mlx,
			game->enemie->frames_text[1]);
	game->enemie->frames_text[2] = mlx_load_png("textures/goblin_4.png");
	game->enemie->frames_img[2] = mlx_texture_to_image(game->mlx,
			game->enemie->frames_text[2]);
	game->enemie->frames_text[3] = mlx_load_png("textures/goblin_3.png");
	game->enemie->frames_img[3] = mlx_texture_to_image(game->mlx,
			game->enemie->frames_text[3]);
	game->enemie->frames_text[4] = mlx_load_png("textures/goblin_5.png");
	game->enemie->frames_img[4] = mlx_texture_to_image(game->mlx,
			game->enemie->frames_text[4]);
	game->enemie->frames_text[5] = mlx_load_png("textures/goblin_6.png");
	game->enemie->frames_img[5] = mlx_texture_to_image(game->mlx,
			game->enemie->frames_text[5]);
	game->enemie->current_frame = 0;
	game->enemie->current_img = game->enemie->frames_img[0];
	game->enemie->move_time = 0;
	game->enemie->total_frames = 7;
}

void	ft_handle_enemie(t_game *game)
{
	game->map->moves++;
	mlx_image_to_window(game->mlx, game->img->game_over_img, (game->map->width * TILE) / 6, (game->map->height * TILE) / 3);
	mlx_put_string(game->mlx, "GAME OVER", (game->map->width * TILE) / 2 - 45, (game->map->height * TILE) / 2 - 20);
	game->game_over_flag = 1;
	ft_printf("Game Over\n");
}

void	set_enemie_position(t_game *game, int i, int j)
{
	game->enemie->e = 1;
	game->enemie->pos_y = i;
	game->enemie->pos_x = j;
	game->game_over_flag = 0;
}

void	ft_move_enemie(t_game *game, int dx, int dy, t_enemie *enemie)
{
	if ((game->map->map[enemie->pos_y][enemie->pos_x + 1] != '1'
		|| game->map->map[enemie->pos_y][enemie->pos_x - 1] != '1') &&
			ft_abs(dx) > ft_abs(dy))
	{
		if (dx > 0 && game->map->map[enemie->pos_y][enemie->pos_x + 1] != '1')
			game->enemie->pos_x += 1;
		else if (game->map->map[enemie->pos_y][enemie->pos_x - 1] != '1')
			game->enemie->pos_x -= 1;
	}
	else if ((game->map->map[enemie->pos_y + 1][enemie->pos_x] != '1'
		|| game->map->map[enemie->pos_y - 1][enemie->pos_x] != '1'))
	{
		if (dy > 0 && game->map->map[enemie->pos_y + 1][enemie->pos_x] != '1')
			game->enemie->pos_y += 1;
		else if (game->map->map[enemie->pos_y - 1][enemie->pos_x] != '1')
			game->enemie->pos_y -= 1;
	}
}

void	update_enemy(t_game *game, double delta_time)
{
	int	dx;
	int	dy;

	game->enemie->move_time += delta_time;
	game->enemie->move_delay = 0.3;
	if (game->enemie->move_time >= game->enemie->move_delay)
	{
		dx = game->player->pos_x - game->enemie->pos_x;
		dy = game->player->pos_y - game->enemie->pos_y;
		mlx_delete_image(game->mlx, game->enemie->current_img);
		game->enemie->current_img = mlx_texture_to_image(game->mlx,
				game->enemie->frames_text[game->player->current_frame]);
		ft_move_enemie(game, dx, dy, game->enemie);
		game->enemie->move_time = 0;
	}
}
