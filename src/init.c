/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:20:11 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/06 11:54:38 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_program(t_game *game)
{
	// game->img = malloc(sizeof(t_image));
	// if (!game->img)
	// 	return ;
	game->mlx = mlx_init(game->map->width * 32, game->map->height * 32, "so_long", true);
	// init_images(game);
	// // ft_printf("I_AM_HERE\n");
	// // set_hooks(game);
	// put_images_in_window(game);
	//finish_game(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

void	init_images(t_game *game)
{
	game->img->floor_text = mlx_load_png("textures/floor.png");
	if (!game->img->floor_text)
	{
		ft_printf("Erro ao carregar a textura!\n");
		return;
	}
	game->img->floor_img = mlx_texture_to_image(game->mlx, game->img->floor_text);
	if (!game->img->floor_img)
	{
		ft_printf("Erro ao converter a textura para imagem!\n");
		return;
	}
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
