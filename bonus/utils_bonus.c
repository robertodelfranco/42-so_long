/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:23:32 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/18 16:20:21 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_player_position(t_game *game, int i, int j)
{
	game->map->p++;
	game->player->pos_y = i;
	game->player->pos_x = j;
}

void	set_exit_position(t_game *game, int i, int j)
{
	game->map->e++;
	game->map->pos_y_e = i;
	game->map->pos_x_e = j;
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	get_delta_time(void)
{
	static double	last_time = 0;
	double			current_time;
	double			delta_time;

	current_time = mlx_get_time();
	delta_time = current_time - last_time;
	last_time = current_time;
	return (delta_time);
}

double	get_delta_time_again(void)
{
	static double	last_time = 0;
	double			current_time;
	double			delta_time;

	current_time = mlx_get_time();
	delta_time = current_time - last_time;
	last_time = current_time;
	return (delta_time);
}
