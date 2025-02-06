/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:31:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/05 17:03:28 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int c, char **v)
{
	t_game	*game;

	if (c != 2)
		return (ft_putstr_fd("Error\nInvalid Args\n", STDERR_FILENO), 0);
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	game->player = malloc(sizeof(t_player));
	init_map(game->map);
	validate_map(v[1], game);
	init_program(game);
	free_and_close(game);
}
