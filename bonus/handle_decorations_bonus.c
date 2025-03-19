/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decorations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:10:01 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 16:19:33 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_tree(t_game *game, int i, int j, int *flag)
{
	if (game->map->map[i][j] == '0' && *flag == 0)
	{
		*flag = 1;
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
			if (j >= game->map->width)
				break ;
			put_tree(game, i, j, &flag);
		}
		flag = i % 2;
	}
}

void	mushroom_rand(t_game *game, int i, int flag)
{
	static int	rand = 0;

	if (game->map->map[i][game->map->width - 2] == '1' && flag == 0)
		mlx_image_to_window(game->mlx, game->img->mushroom_img,
			(game->map->width - 2) * TILE, i * TILE);
	else if (game->map->map[i][game->map->width - 3] == '1' && flag == 1)
		mlx_image_to_window(game->mlx, game->img->mushroom_img,
			(game->map->width - 3) * TILE, i * TILE);
	else
	{
		rand += 1;
		if (game->map->map[i][game->map->width - rand] == '1')
			mlx_image_to_window(game->mlx, game->img->mushroom_img,
				(game->map->width - rand) * TILE, i * TILE);
	}
}

void	put_mushroons(t_game *game, mlx_image_t *mushroom_img)
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
			mlx_image_to_window(game->mlx, mushroom_img, rand * 64, i * 64);
			if (game->map->map[i + 1][rand + 2] == '1')
				rand += 2;
			else if (game->map->map[i + 1][rand + 1] == '1')
				rand += 1;
			else
				rand -= 3;
		}
		if (j == 1 && game->map->map[i][0] == '1')
			mlx_image_to_window(game->mlx, mushroom_img, 0 * 64, i * 64);
		else
			mushroom_rand(game, i, i / 3);
	}
}
