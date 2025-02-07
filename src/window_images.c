/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:28:58 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/07 18:51:58 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images_in_window(void *param)
{
	t_game	*game;
	int	i;
	int	j;

	game = param;
	i = -1;
	while (i++, game->map->map[i] != NULL)
	{
		j = -1;
		while (j++, game->map->map[i][j] != '\0')
		{
			if (game->map->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->img->low_w_img, j * (TILE + 2), i * (TILE + 2));
			else
				mlx_image_to_window(game->mlx, game->img->low_f_img, j * (TILE + 1), i * (TILE + 1));
			if (game->map->map[i][j] == '1' && j != 0 && j != game->map->width - 1 && i != game->map->height - 1 && game->map->map[i + 1][j] != '1')
				mlx_image_to_window(game->mlx, game->img->wall_img, j * TILE, i * TILE);
			else if (game->map->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->img->low_w_img, j * TILE, i * TILE);
			if (game->map->map[i][j] == 'E')
			{
				mlx_image_to_window(game->mlx, game->img->floor_img, j * TILE, i * TILE);
				mlx_image_to_window(game->mlx, game->img->exit_img, j * TILE + 12, i * TILE + 12);
			}
			if (game->map->map[i][j] == 'N')
			{
				mlx_image_to_window(game->mlx, game->img->floor_img, j * TILE, i * TILE);
				mlx_image_to_window(game->mlx, game->img->final_exit_img, j * TILE, i * TILE - 64);
			}
			if (game->map->map[i][j] == 'P')
			{
				mlx_image_to_window(game->mlx, game->img->floor_img, j * TILE, i * TILE);
				mlx_image_to_window(game->mlx, game->player->player_img, j * TILE, i * TILE);
			}
			if (game->map->map[i][j] == 'C')
			{
				mlx_image_to_window(game->mlx, game->img->floor_img, j * TILE, i * TILE);
				mlx_image_to_window(game->mlx, game->img->collectable_img, j * TILE + 20, i * TILE + 20);
			}
			if (game->map->map[i][j] == '0')
				mlx_image_to_window(game->mlx, game->img->floor_img, j * TILE, i * TILE);
		}
	}
}
