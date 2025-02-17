/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:40:24 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/17 15:47:45 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_animate_images(t_game *game)
{
	game->player->frames_text[0] = mlx_load_png("textures/warrior_1.png");
	game->player->frames_img[0] = mlx_texture_to_image(game->mlx,
			game->player->frames_text[0]);
	game->player->frames_text[1] = mlx_load_png("textures/warrior_2.png");
	game->player->frames_img[1] = mlx_texture_to_image(game->mlx,
			game->player->frames_text[1]);
	game->player->frames_text[2] = mlx_load_png("textures/warrior_3.png");
	game->player->frames_img[2] = mlx_texture_to_image(game->mlx,
			game->player->frames_text[2]);
	game->player->frames_text[3] = mlx_load_png("textures/warrior_4.png");
	game->player->frames_img[3] = mlx_texture_to_image(game->mlx,
			game->player->frames_text[3]);
	game->player->frames_text[4] = mlx_load_png("textures/warrior_5.png");
	game->player->frames_img[4] = mlx_texture_to_image(game->mlx,
			game->player->frames_text[4]);
	game->player->frames_text[5] = mlx_load_png("textures/warrior_6.png");
	game->player->frames_img[5] = mlx_texture_to_image(game->mlx,
			game->player->frames_text[5]);
	game->player->current_frame = 0;
	game->player->current_img = game->player->frames_img[0];
	game->player->total_frames = 6;
	game->player->frame_time = 0;
	game->player->frame_move_delay = 0.2;
}

void	load_dead_images(t_game *game)
{
	game->dead->dead_text[0] = mlx_load_png("textures/dead.png");
	game->dead->dead_img[0] = mlx_texture_to_image(game->mlx,
			game->dead->dead_text[0]);
	mlx_resize_image(game->dead->dead_img[0], 20, 20);
	game->dead->dead_text[1] = mlx_load_png("textures/dead_1.png");
	game->dead->dead_img[1] = mlx_texture_to_image(game->mlx,
			game->dead->dead_text[1]);
	mlx_resize_image(game->dead->dead_img[1], 20, 20);
	game->dead->dead_text[2] = mlx_load_png("textures/dead_2.png");
	game->dead->dead_img[2] = mlx_texture_to_image(game->mlx,
			game->dead->dead_text[2]);
	mlx_resize_image(game->dead->dead_img[2], 20, 20);
	game->dead->dead_text[3] = mlx_load_png("textures/dead_3.png");
	game->dead->dead_img[3] = mlx_texture_to_image(game->mlx,
			game->dead->dead_text[3]);
	mlx_resize_image(game->dead->dead_img[3], 20, 20);
	game->dead->dead_text[4] = mlx_load_png("textures/dead_4.png");
	game->dead->dead_img[4] = mlx_texture_to_image(game->mlx,
			game->dead->dead_text[4]);
	mlx_resize_image(game->dead->dead_img[4], 20, 20);
	game->dead->current_img = game->dead->dead_img[0];	
}

void	update_dead(t_game *game, double delta_time)
{
	static int	first = 0;

	game->dead->move_time += delta_time;
	game->dead->frame_delay = 0.3;
	if (first == 0)
	{
		game->player->current_frame = 0;
		first = 1;
	}
	if (game->dead->move_time >= game->dead->frame_delay)
	{
		mlx_delete_image(game->mlx, game->dead->current_img);
		game->dead->current_img = mlx_texture_to_image(game->mlx,
				game->dead->dead_text[game->player->current_frame]);
		mlx_image_to_window(game->mlx, game->dead->current_img,
			game->player->pos_x * TILE + 7, game->player->pos_y * TILE + 14);
		game->player->current_frame = (game->player->current_frame + 1) % 5;
		game->dead->move_time = 0;
	}
}
