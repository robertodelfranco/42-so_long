/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemie_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:30:54 by marvin            #+#    #+#             */
/*   Updated: 2025/02/13 12:30:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_enemie_common_move(t_game *game, int x, int y)
{
	game->map->map[game->enemie->pos_y][game->enemie->pos_x] = '0';
	game->enemie->pos_x += x;
	game->enemie->pos_y += y;
	game->map->map[game->enemie->pos_y][game->enemie->pos_x] = 'I';
}
