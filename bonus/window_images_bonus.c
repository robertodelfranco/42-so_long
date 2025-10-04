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

#include "../includes/so_long_bonus.h"

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

bool	has_a_tree(t_game *game, double x, double y)
{
	size_t i;

	i = 0;
	while (i < game->img->tree_img->count)
	{
		if (game->img->tree_img->instances[i].x == x * TILE - 16
			&& game->img->tree_img->instances[i].y == y * TILE)
			return (true);
		i++;
	}
	return (false);
}

void	render_player(t_game *game)
{
	if (game->player->current_img)
		mlx_delete_image(game->mlx, game->player->current_img);
	game->player->current_img = mlx_texture_to_image(game->mlx,
		game->player->frames_text[game->player->current_frame]);
	mlx_resize_image(game->player->current_img, 32, 32);
	mlx_image_to_window(game->mlx, game->player->current_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	if (has_a_tree(game, game->player->pos_x, game->player->pos_y))
		mlx_set_instance_depth(&game->player->current_img->instances[0], -1);
	else
		mlx_set_instance_depth(&game->player->current_img->instances[0], 1);
}

void	put_exits(t_game *game, int i, int j)
{
	if (game->map->map[i][j] == 'E')
	{
		mlx_image_to_window(game->mlx, game->img->floor_img,
			j * TILE, i * TILE);
		mlx_image_to_window(game->mlx, game->img->exit_img,
			j * TILE + 17, i * TILE + 34);
		mlx_set_instance_depth(&game->img->exit_img->instances[0], -1);
	}
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
					j * TILE, i * TILE);
		}
	}
	mlx_image_to_window(game->mlx, game->img->ribbon_img, 0, 0 + 2);
	find_tile(game);
	set_depth(game->img->tree_img, 0);
	set_depth(game->img->floor_img, -3);
	set_depth(game->img->collectable_img, -2);
}
