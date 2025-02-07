/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:20:11 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/06 18:53:55 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_program(t_game *game)
{
	game->img = malloc(sizeof(t_image));
	if (!game->img)
		return ;
	game->mlx = mlx_init(game->map->width * TILE, game->map->height * TILE, "so_long", false);
	init_images(game);
	init_images_again(game);
	put_images_in_window(game);
	
	mlx_loop_hook(game->mlx, ft_player, game);

	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

void	init_images(t_game *game)
{
	game->img->floor_text = mlx_load_png("textures/floor.png");
	game->img->floor_img = mlx_texture_to_image(game->mlx, game->img->floor_text);
	mlx_resize_image(game->img->floor_img, TILE, TILE);
	if (!game->img->floor_img)
		message_error(EXIT_INVALID_FILE, game);
	game->img->wall_text = mlx_load_png("textures/wall_grass.png");
	game->img->wall_img = mlx_texture_to_image(game->mlx, game->img->wall_text);
	mlx_resize_image(game->img->wall_img, TILE, TILE);
	if (!game->img->wall_img)
		message_error(EXIT_INVALID_FILE, game);
	game->img->low_w_text = mlx_load_png("textures/low_wall.png");
	game->img->low_w_img = mlx_texture_to_image(game->mlx, game->img->low_w_text);
	mlx_resize_image(game->img->low_w_img, TILE, TILE);
	if (!game->img->low_w_img)
		message_error(EXIT_INVALID_FILE, game);
	game->img->exit_text = mlx_load_png("textures/exit.png");
	game->img->exit_img = mlx_texture_to_image(game->mlx, game->img->exit_text);
	mlx_resize_image(game->img->exit_img, 40, 40);
	if (!game->img->exit_img)
		message_error(EXIT_INVALID_FILE, game);
	game->img->final_exit_text = mlx_load_png("textures/final_exit.png");
	game->img->final_exit_img = mlx_texture_to_image(game->mlx, game->img->final_exit_text);
	mlx_resize_image(game->img->final_exit_img, TILE, 128);
	if (!game->img->final_exit_img)
		message_error(EXIT_INVALID_FILE, game);
}

void	init_images_again(t_game *game)
{
	game->img->collectable_text = mlx_load_png("textures/collectable.png");
	game->img->collectable_img = mlx_texture_to_image(game->mlx, game->img->collectable_text);
	mlx_resize_image(game->img->collectable_img, 24, 24);
	if (!game->img->collectable_img)
		message_error(EXIT_INVALID_FILE, game);
	game->player->player_text = mlx_load_png("textures/Warrior_Blue.png");
	game->player->player_img = mlx_texture_to_image(game->mlx, game->player->player_text);
	mlx_resize_image(game->player->player_img, TILE, TILE);
	if (!game->player->player_text)
		message_error(EXIT_INVALID_FILE, game);
	game->img->low_f_text = mlx_load_png("textures/low_floor.png");
	game->img->low_f_img = mlx_texture_to_image(game->mlx, game->img->low_f_text);
	mlx_resize_image(game->img->low_f_img, 65, 65);
	if (!game->img->low_f_img)
		message_error(EXIT_INVALID_FILE, game);
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->c = 0;
	map->p = 0;
	map->e = 0;
	map->moves = 0;
}
