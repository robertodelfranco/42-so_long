/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:31:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/18 15:34:22 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int c, char **v)
{
	t_game	*game;

	if (c != 2)
		return (ft_putstr_fd("Error\nInvalid Args\n", STDERR_FILENO), 0);
	game = ft_calloc(1, sizeof(t_game));
	game->dead = ft_calloc(1, sizeof(t_dead));
	game->enemie = ft_calloc(1, sizeof(t_enemie));
	game->player = ft_calloc(1, sizeof(t_player));
	game->map = ft_calloc(1, sizeof(t_map));
	game->file = v[1];
	validate_map(v[1], game);
	init_program(game);
	free_and_close(game);
}
