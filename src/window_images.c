/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:28:58 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/10 19:33:07 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images_in_window(void *param)
{
	t_game	*game;
	int		i;
	int		j;

	game = param;
	i = -1;
	while (i++, game->map->map[i] != NULL)
	{
		j = -1;
		while (j++, game->map->map[i][j] != '\0')
		{
			mlx_image_to_window(game->mlx, game->img->low_w_img, j * TILE, i * TILE);
			if (game->map->map[i][j] == '1' && i == game->map->height - 1)
				mlx_image_to_window(game->mlx, game->img->wall_img, j * TILE, i * TILE);
			else if (game->map->map[i][j] == '1' && j != 0 && j != game->map->width - 1 && i != game->map->height - 1 && game->map->map[i + 1][j] != '1')
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
				mlx_image_to_window(game->mlx, game->player->player_img, j * TILE + 7, i * TILE + 7);
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
	find_tile(game);
}

void	put_mushroons(t_game *game)
{
	int	i;
	int	j;
	int	rand;

	i = -1;
	j = (game->map->width - 4);
	rand = game->map->width / 2;
	while (i++, game->map->map[i])
	{
		j = i % 2;
		if (game->map->map[i][rand] == '1' && i != game->map->height - 1)
		{
			mlx_image_to_window(game->mlx, game->img->mushroom_img, rand * TILE, i * TILE);
			if (game->map->map[i + 1][rand + 2] == '1')
				rand += 2;
			else if (game->map->map[i + 1][rand + 1] == '1')
				rand += 1;
			else
				rand -= 3;
		}
		if (j == 1)
			mlx_image_to_window(game->mlx, game->img->mushroom_img, 0 * TILE, i * TILE);
		else
			mlx_image_to_window(game->mlx, game->img->mushroom_img, (game->map->width - 1) * TILE, i * TILE);
	}
}

void	find_tile(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (game->map->map[i][j])
	{
		if (game->map->map[i][game->map->width - j] == '0')
		{
			game->map->map[i][game->map->width - j] = 'T';
			mlx_image_to_window(game->mlx, game->img->tree_img, (game->map->width - j) * TILE, i * TILE);
			return ;
		}
		j++;
	}
}
