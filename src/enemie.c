/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:58:20 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/13 00:03:29 by rdel-fra         ###   ########.fr       */
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
	game->enemie->frames_text[6] = mlx_load_png("textures/goblin_7.png");
	game->enemie->frames_img[6] = mlx_texture_to_image(game->mlx,
			game->enemie->frames_text[6]);
	game->enemie->current_frame = 0;
	game->enemie->current_img = game->enemie->frames_img[0];
	game->enemie->total_frames = 7;
}

// void	ft_handle_enemie(t_game *game)
// {
// 	game->map->moves++;
// 	ft_printf("Game Over\n");
// 	free_and_close(game);
// }

void	set_enemie_position(t_game *game, int i, int j)
{
	game->enemie->e++;
	game->enemie->pos_y = i;
	game->enemie->pos_x = j;
}
