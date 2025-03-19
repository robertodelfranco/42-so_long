/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:15:27 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/18 15:46:17 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	mlx_delete_image(game->mlx, game->player->current_img);
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
	}
}

void	free_and_close(t_game *game)
{
	delete_images(game);
	mlx_terminate(game->mlx);
	ft_free(game->map->map, ft_ptrlen(game->map->map));
	ft_free(game->map->map_copy, ft_ptrlen(game->map->map_copy));
	free(game->player);
	free(game->img);
	free(game->map);
	free(game);
	exit(0);
}
