/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decorations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:10:01 by marvin            #+#    #+#             */
/*   Updated: 2025/02/11 12:10:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_tree(t_game *game, int move_x, int move_y)
{
	mlx_image_to_window(game->mlx, game->img->floor_img,
		game->player->pos_x * TILE, game->player->pos_y * TILE);
	if (game->map->map[game->player->pos_y][game->player->pos_x] == 'T')
		mlx_image_to_window(game->mlx, game->img->tree_img,
			game->player->pos_x * TILE, game->player->pos_y * TILE);
	else if (game->map->map[game->player->pos_y][game->player->pos_x] != 'E')
		game->map->map[game->player->pos_y][game->player->pos_x] = '0';
	else
		mlx_image_to_window(game->mlx, game->img->exit_img,
			game->player->pos_x * TILE + 12, game->player->pos_y * TILE + 12);
	game->map->moves++;
	game->player->pos_x += move_x;
	game->player->pos_y += move_y;
}

void	put_tree(t_game *game, int i, int j, int *flag)
{
	if (game->map->map[i][j] == '0' && *flag == 0)
	{
		*flag = 2;
		game->map->map[i][j] = 'T';
		mlx_image_to_window(game->mlx, game->img->tree_img, j * TILE, i * TILE);
	}
	else if (game->map->map[i][game->map->width - j - 1] == '0' && *flag == 1)
	{
		*flag = 2;
		game->map->map[i][game->map->width - j - 1] = 'T';
		mlx_image_to_window(game->mlx, game->img->tree_img,
			(game->map->width - j - 1) * TILE, i * TILE);
	}
}

void	find_tile(t_game *game)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i++, game->map->map[i] && i < game->map->height)
	{
		j = 0;
		while (game->map->map[i][j] && j < game->map->width)
		{
			j += i;
			put_tree(game, i, j, &flag);
		}
		flag = i % 2;
	}
}
