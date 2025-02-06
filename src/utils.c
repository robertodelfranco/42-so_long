/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:23:32 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/06 18:24:37 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_position(t_game *game, int i, int j)
{
	game->player->pos_y = i;
	game->player->pos_x = j;
}

void	set_exit_position(t_game *game, int i, int j)
{
	game->map->pos_y_e = i;
	game->map->pos_x_e = j;
}
