/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:58:20 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/18 16:19:07 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	game->enemie->total_frames = 6;
	game->enemie->move_time = 0;
}

void	ft_handle_enemie(t_game *game)
{
	game->map->moves++;
	mlx_delete_image(game->mlx, game->player->current_img);
	mlx_image_to_window(game->mlx, game->img->game_over_img,
		((game->map->width * TILE) - (game->map->width * TILE / 3 * 2)) / 2,
		((game->map->height * TILE) - (game->map->height * TILE / 3)) / 2);
	mlx_image_to_window(game->mlx, game->img->phrase_game_over_img,
		((game->map->width * TILE) - (game->map->width * TILE / 4)) / 2,
		((game->map->height * TILE) - (game->map->height * TILE / 4)) / 2);
	game->game_over_flag = 1;
	ft_printf("Game Over\n");
}

void	set_enemie_position(t_game *game, int i, int j)
{
	game->enemie->e = 1;
	game->enemie->pos_y = i;
	game->enemie->pos_x = j;
	game->game_over_flag = 0;
	game->dead->move_time = 0;
}

static void	ft_move_enemie(t_game *game, double dx, double dy, t_enemie *enemie)
{
	if (fabs(dx) > fabs(dy)) {
		if (dx > 0 && game->map->map[(int)enemie->pos_y][(int)(enemie->pos_x + 0.5)] != '1')
			enemie->pos_x += 0.5;
		else if (game->map->map[(int)enemie->pos_y][(int)(enemie->pos_x - 0.5)] != '1')
			enemie->pos_x -= 0.5;
	}
	else
	{
		if (dy > 0 && game->map->map[(int)(enemie->pos_y + 0.5)][(int)enemie->pos_x] != '1')
			enemie->pos_y += 0.5;
		else if (game->map->map[(int)(enemie->pos_y - 0.5)][(int)enemie->pos_x] != '1')
			enemie->pos_y -= 0.5;
	}
}

void	update_enemy(t_game *game, double delta_time)
{
	double	dx;
	double	dy;

	game->enemie->move_time += delta_time;
	game->enemie->move_delay = 0.2;
	if (game->enemie->move_time >= game->enemie->move_delay)
	{
		dx = game->player->pos_x - game->enemie->pos_x;
		dy = game->player->pos_y - game->enemie->pos_y;
		if (game->enemie->current_img)
			mlx_delete_image(game->mlx, game->enemie->current_img);
		game->enemie->current_img = mlx_texture_to_image(game->mlx,
				game->enemie->frames_text[game->enemie->current_frame]);
		mlx_resize_image(game->enemie->current_img, 32, 32);
		ft_move_enemie(game, dx, dy, game->enemie);
		mlx_image_to_window(game->mlx, game->enemie->current_img,
			game->enemie->pos_x * TILE, game->enemie->pos_y * TILE);
		if (has_a_tree(game, game->enemie->pos_x, game->enemie->pos_y))
			mlx_set_instance_depth(&game->enemie->current_img->instances[0], -1);
		else
			mlx_set_instance_depth(&game->enemie->current_img->instances[0], 1);
		game->enemie->move_time = 0;
	}
}
