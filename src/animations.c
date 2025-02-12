/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:40:24 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/12 18:33:34 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	load_animate_images(t_game *game)
{
	game->player->frames_text[0] = mlx_load_png("textures/warrior_1.png");
	game->player->frames_img[0] = mlx_texture_to_image(game->mlx, game->player->frames_text[0]);
	game->player->frames_text[1] = mlx_load_png("textures/warrior_2.png");
	game->player->frames_img[1] = mlx_texture_to_image(game->mlx, game->player->frames_text[1]);
	game->player->frames_text[2] = mlx_load_png("textures/warrior_3.png");
	game->player->frames_img[2] = mlx_texture_to_image(game->mlx, game->player->frames_text[2]);
	game->player->frames_text[3] = mlx_load_png("textures/warrior_4.png");
	game->player->frames_img[3] = mlx_texture_to_image(game->mlx, game->player->frames_text[3]);
	game->player->frames_text[4] = mlx_load_png("textures/warrior_5.png");
	game->player->frames_img[4] = mlx_texture_to_image(game->mlx, game->player->frames_text[4]);
	game->player->frames_text[5] = mlx_load_png("textures/warrior_6.png");
	game->player->frames_img[5] = mlx_texture_to_image(game->mlx, game->player->frames_text[5]);
	game->player->current_frame = 0;
	game->player->current_img = game->player->frames_img[0];
	game->player->total_frames = 6;
	game->player->move_delay = 0.2;
}
