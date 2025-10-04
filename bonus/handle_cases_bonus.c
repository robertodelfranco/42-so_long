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

void	ft_handle_exit(t_game *game, double x, double y)
{
	game->map->moves++;
	game->player->pos_x = x;
	game->player->pos_y = y;
}

void	ft_handle_common_move(t_game *game, double x, double y)
{
	game->map->moves++;
	game->player->pos_x = x;
	game->player->pos_y = y;
}

void	ft_handle_collectable(t_game *game, double x, double y)
{
	if (disable_instances(game->img->collectable_img, x * 64, y * 64)) {
		game->map->c_now--;
	}
	game->map->moves++;
	game->player->pos_x = x;
	game->player->pos_y = y;
}

void	ft_handle_last_collectable(t_game *game, double x, double y)
{
	if (disable_instances(game->img->collectable_img, x * 64, y * 64)) {	
		game->map->c_now--;
		game->map->map[game->map->pos_y_e][game->map->pos_x_e] = 'N';
		mlx_image_to_window(game->mlx, game->img->final_exit_img,
			game->map->pos_x_e * TILE, game->map->pos_y_e * TILE);
		mlx_set_instance_depth(&game->img->final_exit_img->instances[0], 0);
	}
	game->map->moves++;
	game->player->pos_x = x;
	game->player->pos_y = y;
}

void	ft_handle_final_exit(t_game *game)
{
	game->map->moves++;
	mlx_delete_image(game->mlx, game->enemie->current_img);
	mlx_delete_image(game->mlx, game->player->current_img);
	mlx_image_to_window(game->mlx, game->img->game_win_img,
		((game->map->width * TILE) - (game->map->width * TILE / 3 * 2)) / 2,
		((game->map->height * TILE) - (game->map->height * TILE / 3)) / 2);
	mlx_image_to_window(game->mlx, game->img->phrase_game_win_img,
		((game->map->width * TILE) - (game->map->width * TILE / 4)) / 2,
		((game->map->height * TILE) - (game->map->height * TILE / 4)) / 2);
	game->game_win_flag = 1;
	ft_printf("You Win!\n");
}
