/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:45:22 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/14 20:18:30 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_game *game)
{
	int	i;
	int	j;
	int	line_length;

	game->map->map_copy = malloc(sizeof(char *) * (game->map->height + 1));
	line_length = game->map->width + 1;
	i = 0;
	while (game->map->map[i])
	{
		game->map->map_copy[i] = malloc(sizeof(char) * line_length);
		j = 0;
		while (game->map->map[i][j])
		{
			game->map->map_copy[i][j] = game->map->map[i][j];
			j++;
		}
		game->map->map_copy[i][j] = '\0';
		i++;
	}
	game->map->map_copy[i] = NULL;
	flood_fill(game, game->player->pos_x, game->player->pos_y);
	verify_flood_fill(game);
}

void	verify_flood_fill(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map_copy[i])
	{
		j = 0;
		while (game->map->map_copy[i][j])
		{
			if (game->map->map_copy[i][j] == 'E')
				message_error(EXIT_NO_PATH, game);
			if (game->map->map_copy[i][j] == 'C')
				message_error(EXIT_NO_PATH, game);
			j++;
		}
		i++;
	}
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x <= 0 || y <= 0 || x >= (game->map->width - 1)
		|| y >= (game->map->height - 1))
		return ;
	if (game->map->map_copy[y][x] == '1' || game->map->map_copy[y][x] == 'X')
		return ;
	if (game->map->map_copy[y][x] == '0' || game->map->map_copy[y][x] == 'C'
		|| game->map->map_copy[y][x] == 'E' || game->map->map_copy[y][x] == 'P'
			|| game->map->map_copy[y][x] == 'I')
	{
		game->map->map_copy[y][x] = 'X';
		flood_fill(game, x + 1, y);
		flood_fill(game, x - 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
}
