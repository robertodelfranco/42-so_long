/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:28:58 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/06 11:44:30 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images_in_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i] != NULL)
	{
		j = 0;
		while (game->map->map[i][j] != '\0')
		{
			ft_printf("1\n");
			if (game->map->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->img->floor_img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}