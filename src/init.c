/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:20:11 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/17 15:51:40 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_program(t_game *game)
{
	game->img = malloc(sizeof(t_image));
	if (!game->img)
		return ;
	game->mlx = (mlx_t *)mlx_init(game->map->width * TILE,
			game->map->height * TILE, "so_long", false);
	init_images(game);
	init_images_again(game);
	init_images_once_again(game);
	put_images_in_window(game);
	put_mushroons(game, game->img->mushroom_img);
	mlx_key_hook(game->mlx, main_move, game);
	mlx_loop_hook(game->mlx, ft_player, game);
	mlx_loop(game->mlx);
	free_and_close(game);
	mlx_terminate(game->mlx);
}

void	init_images(t_game *game)
{
	game->img->floor_text = mlx_load_png("textures/floor.png");
	game->img->floor_img = mlx_texture_to_image(game->mlx,
			game->img->floor_text);
	mlx_delete_texture(game->img->floor_text);
	mlx_resize_image(game->img->floor_img, TILE, TILE);
	game->img->wall_text = mlx_load_png("textures/wall_grass.png");
	game->img->wall_img = mlx_texture_to_image(game->mlx,
			game->img->wall_text);
	mlx_resize_image(game->img->wall_img, TILE, TILE);
	mlx_delete_texture(game->img->wall_text);
	game->img->low_w_text = mlx_load_png("textures/low_wall.png");
	game->img->low_w_img = mlx_texture_to_image(game->mlx,
			game->img->low_w_text);
	mlx_resize_image(game->img->low_w_img, 68, 68);
	mlx_delete_texture(game->img->low_w_text);
	game->img->exit_text = mlx_load_png("textures/exit.png");
	game->img->exit_img = mlx_texture_to_image(game->mlx,
			game->img->exit_text);
	mlx_resize_image(game->img->exit_img, 30, 30);
	mlx_delete_texture(game->img->exit_text);
	game->img->final_exit_text = mlx_load_png("textures/house.png");
	game->img->final_exit_img = mlx_texture_to_image(game->mlx,
			game->img->final_exit_text);
	mlx_resize_image(game->img->final_exit_img, TILE, TILE);
	mlx_delete_texture(game->img->final_exit_text);
}

void	init_images_again(t_game *game)
{
	load_animate_images(game);
	load_enemie_animation(game);
	game->img->collectable_text = mlx_load_png("textures/collectable.png");
	game->img->collectable_img = mlx_texture_to_image(game->mlx,
			game->img->collectable_text);
	mlx_resize_image(game->img->collectable_img, 24, 24);
	mlx_delete_texture(game->img->collectable_text);
	game->img->mushroom_text = mlx_load_png("textures/mushroom.png");
	game->img->mushroom_img = mlx_texture_to_image(game->mlx,
			game->img->mushroom_text);
	mlx_delete_texture(game->img->mushroom_text);
	game->img->tree_text = mlx_load_png("textures/tree_a.png");
	game->img->tree_img = mlx_texture_to_image(game->mlx,
			game->img->tree_text);
	mlx_resize_image(game->img->tree_img, TILE, TILE);
	mlx_delete_texture(game->img->tree_text);
	game->img->ribbon_text = mlx_load_png("textures/ribbon.png");
	game->img->ribbon_img = mlx_texture_to_image(game->mlx,
			game->img->ribbon_text);
	mlx_resize_image(game->img->ribbon_img, 192, 44);
	mlx_delete_texture(game->img->ribbon_text);
}

void	init_images_once_again(t_game *game)
{
	load_dead_images(game);
	game->img->game_over_text = mlx_load_png("textures/game_over.png");
	game->img->game_over_img = mlx_texture_to_image(game->mlx,
			game->img->game_over_text);
	mlx_resize_image(game->img->game_over_img,
		((game->map->width * TILE) / 3) * 2, (game->map->height * TILE) / 3);
	mlx_delete_texture(game->img->game_over_text);
	game->img->phrase_game_over_text = mlx_load_png("textures/phrase.png");
	game->img->phrase_game_over_img = mlx_texture_to_image(game->mlx,
			game->img->phrase_game_over_text);
	mlx_resize_image(game->img->phrase_game_over_img,
		(game->map->width * TILE) / 4, (game->map->height * TILE) / 7);
	mlx_delete_texture(game->img->phrase_game_over_text);
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
