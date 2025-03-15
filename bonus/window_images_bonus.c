/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:28:58 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/18 16:20:50 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_wall(t_game *game, int i, int j)
{
	if (game->map->map[i][j] == '1' && i == game->map->height - 1)
		mlx_image_to_window(game->mlx, game->img->wall_img,
			j * TILE, i * TILE);
	else if (game->map->map[i][j] == '1' && j != 0 && j != game->map->width - 1
			&& i != game->map->height - 1 && game->map->map[i + 1][j] != '1')
		mlx_image_to_window(game->mlx, game->img->wall_img,
			j * TILE, i * TILE);
	else if (game->map->map[i][j] == '1')
		mlx_image_to_window(game->mlx, game->img->low_w_img,
			j * TILE, i * TILE);
}

void	render_player(t_game *game)
{
	if (game->player->current_img)
		mlx_delete_image(game->mlx, game->player->current_img);
	game->player->current_img = mlx_texture_to_image(game->mlx,
			game->player->frames_text[game->player->current_frame]);
	mlx_resize_image(game->player->current_img, 50, 50);
	mlx_image_to_window(game->mlx, game->player->current_img,
		game->player->pos_x * TILE + 7, game->player->pos_y * TILE + 14);
	if (game->enemie->e > 0)
	{
		if (game->enemie->current_img)
			mlx_image_to_window(game->mlx, game->img->floor_img,
				game->enemie->pos_x * TILE, game->enemie->pos_y * TILE);
		game->enemie->current_img = mlx_texture_to_image(game->mlx,
				game->enemie->frames_text[game->player->current_frame]);
		mlx_resize_image(game->enemie->current_img, 50, 50);
		mlx_image_to_window(game->mlx, game->enemie->current_img,
			game->enemie->pos_x * TILE + 7, game->enemie->pos_y * TILE + 14);
		if (ft_strnstr(game->file, "mov", ft_strlen(game->file)))
			map_restore(game);
	}
}

void	put_exits(t_game *game, int i, int j)
{
	if (game->map->map[i][j] == 'E')
	{
		mlx_image_to_window(game->mlx, game->img->floor_img,
			j * TILE, i * TILE);
		mlx_image_to_window(game->mlx, game->img->exit_img,
			j * TILE + 17, i * TILE + 34);
	}
}

void	map_restore(t_game *game)
{
	if (game->map->map[game->enemie->pos_y][game->enemie->pos_x] == 'T')
		mlx_image_to_window(game->mlx, game->img->tree_img,
			game->enemie->pos_x * TILE, game->enemie->pos_y * TILE);
	else if (game->map->map[game->enemie->pos_y][game->enemie->pos_x] == 'C')
		mlx_image_to_window(game->mlx, game->img->collectable_img,
			game->enemie->pos_x * TILE + 20, game->enemie->pos_y * TILE + 20);
	else if (game->map->map[game->enemie->pos_y][game->enemie->pos_x] == 'E')
		mlx_image_to_window(game->mlx, game->img->exit_img,
			game->enemie->pos_x * TILE + 17, game->enemie->pos_y * TILE + 34);
	else if (game->map->map[game->enemie->pos_y][game->enemie->pos_x] == 'N')
		mlx_image_to_window(game->mlx, game->img->final_exit_img,
			game->enemie->pos_x * TILE, game->enemie->pos_y * TILE);
}

void	put_images_in_window(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (i++, game->map->map[i] != NULL)
	{
		j = -1;
		while (j++, game->map->map[i][j] != '\0')
		{
			if (game->map->map[i][j] == '1')
				put_wall(game, i, j);
			if (game->map->map[i][j] != '1')
				mlx_image_to_window(game->mlx, game->img->floor_img,
					j * TILE, i * TILE);
			if (game->map->map[i][j] == 'E')
				put_exits(game, i, j);
			if (game->map->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->img->collectable_img,
					j * TILE + 20, i * TILE + 20);
		}
	}
	mlx_image_to_window(game->mlx, game->img->ribbon_img, 0, 0 + 2);
	find_tile(game);
}
