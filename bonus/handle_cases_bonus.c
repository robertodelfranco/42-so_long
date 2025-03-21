/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cases_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:22:58 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/18 16:19:19 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_handle_exit(t_game *game, int x, int y)
{
	game->map->moves++;
	game->player->pos_x = x;
	game->player->pos_y = y;
}

void	ft_handle_common_move(t_game *game, int x, int y)
{
	game->map->moves++;
	game->player->pos_x = x;
	game->player->pos_y = y;
}

void	ft_handle_collectable(t_game *game, int x, int y)
{
	disable_instances(game->img->collectable_img, x * 64 + 20, y * 64 + 20);
	game->map->c_now--;
	game->map->moves++;
	game->player->pos_x = x;
	game->player->pos_y = y;
}

void	ft_handle_last_collectable(t_game *game, int x, int y)
{
	disable_instances(game->img->collectable_img, x * 64 + 20, y * 64 + 20);
	game->map->c_now--;
	game->map->moves++;
	game->player->pos_x = x;
	game->player->pos_y = y;
	game->map->map[game->map->pos_y_e][game->map->pos_x_e] = 'N';
	mlx_image_to_window(game->mlx, game->img->final_exit_img,
		game->map->pos_x_e * TILE, game->map->pos_y_e * TILE);
}

void	ft_handle_final_exit(t_game *game)
{
	game->map->moves++;
	mlx_close_window(game->mlx);
	free_and_close(game);
}
