/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:45:35 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/10 19:04:39 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message_error(short error_code, t_game *game)
{
	if (error_code == EXIT_INVALID_FILE)
		ft_putstr_fd("Error\nInvalid File\n", STDERR_FILENO);
	if (error_code == EXIT_INVALID_EXTENTION)
		ft_putstr_fd("Error\nInvalid File Extention\n", STDERR_FILENO);
	if (error_code == EXIT_INVALID_CHAR)
		ft_putstr_fd("Error\nInvalid Character\n", STDERR_FILENO);
	if (error_code == EXIT_MUST_BE_RECTANGULAR)
		ft_putstr_fd("Error\nMap must be rectangular\n", STDERR_FILENO);
	if (error_code == EXIT_LINE_SIZE)
		ft_putstr_fd("Error\nLines must have the same size\n", STDERR_FILENO);
	if (error_code == EXIT_TOO_SHORT)
		ft_putstr_fd("Error\nMap must be at least 15 tiles\n", STDERR_FILENO);
	if (error_code == EXIT_MISSING_E)
		ft_putstr_fd("Error\nMap must have one exit\n", STDERR_FILENO);
	if (error_code == EXIT_MISSING_P)
		ft_putstr_fd("Error\nMap must have one player\n", STDERR_FILENO);
	if (error_code == EXIT_MISSING_C)
		ft_putstr_fd("Error\nMap must have collectables\n", STDERR_FILENO);
	free_and_close(game);
	exit(2);
}

void	free_and_close(t_game *game)
{
	ft_free(game->map->map, ft_ptrlen(game->map->map));
	free(game->player);
	free(game->map);
	free(game);
	exit(0);
}

void	ft_free(char **ptr_matrix, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(ptr_matrix[i]);
		i++;
	}
	free(ptr_matrix);
}

void	ft_clear_window(t_game *game)
{
	mlx_close_window(game->mlx);
	free_and_close(game);
}
