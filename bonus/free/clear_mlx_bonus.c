/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:15:27 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/18 16:19:06 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->img->floor_img);
	mlx_delete_image(game->mlx, game->img->wall_img);
	mlx_delete_image(game->mlx, game->img->low_w_img);
	mlx_delete_image(game->mlx, game->img->exit_img);
	mlx_delete_image(game->mlx, game->img->final_exit_img);
	mlx_delete_image(game->mlx, game->img->collectable_img);
	mlx_delete_image(game->mlx, game->img->mushroom_img);
	mlx_delete_image(game->mlx, game->img->tree_img);
	mlx_delete_image(game->mlx, game->img->ribbon_img);
	mlx_delete_image(game->mlx, game->enemie->current_img);
	mlx_delete_image(game->mlx, game->player->current_img);
	mlx_delete_image(game->mlx, game->img->game_win_img);
	mlx_delete_image(game->mlx, game->img->phrase_game_win_img);
	free_animate_images(game);
}

void	free_animate_images(t_game *game)
{
	int	i;

	i = 6;
	while (i--)
	{
		mlx_delete_texture(game->player->frames_text[i]);
		mlx_delete_image(game->mlx, game->player->frames_img[i]);
		mlx_delete_texture(game->enemie->frames_text[i]);
		mlx_delete_image(game->mlx, game->enemie->frames_img[i]);
		if (i < 5)
		{
			mlx_delete_texture(game->dead->dead_text[i]);
			mlx_delete_image(game->mlx, game->dead->dead_img[i]);
		}
	}
}

void	free_and_close(t_game *game)
{
	delete_images(game);
	mlx_terminate(game->mlx);
	ft_free(game->map->map, ft_ptrlen(game->map->map));
	ft_free(game->map->map_copy, ft_ptrlen(game->map->map_copy));
	free(game->dead);
	free(game->player);
	free(game->enemie);
	free(game->img);
	free(game->map);
	free(game);
	exit(0);
}
