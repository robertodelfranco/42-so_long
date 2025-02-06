/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:56:11 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/06 11:55:01 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i] != NULL)
	{
		j = 0;
		while (game->map->map[i][j] != '\0' && game->map->map[i][j] != '\n')
		{
			if (game->map->map[i][j] == 'C')
				game->map->c++;
			if (game->map->map[i][j] == 'E')
				game->map->e++;
			if (game->map->map[i][j] == 'P')
			{
				game->map->p++;
				game->player->x = j;
				game->player->y = i;
			}
			if (!ft_strchr("01CEP", game->map->map[i][j]))
				message_error(EXIT_INVALID_CHAR, game);
			j++;
		}
		i++;
	}
	verify_map(game);
}

void	verify_map(t_game *game)
{
	game->map->height = ft_ptrlen(game->map->map);
	game->map->width = ft_strlen(game->map->map[0]);
	ft_printf("height: %d\n", game->map->height);
	ft_printf("width: %d\n", game->map->width);
	if (game->map->height == game->map->width)
		message_error(EXIT_MUST_BE_RECTANGULAR, game);
	if ((game->map->height * game->map->width) % game->map->height != 0)
		message_error(EXIT_LINE_SIZE, game);
	if (game->map->height < 3 || game->map->width < 3)
		message_error(EXIT_TOO_SHORT, game);
	if ((game->map->height * game->map->width) < 15)
		message_error(EXIT_TOO_SHORT, game);
	if (game->map->e != 1)
		message_error(EXIT_MISSING_E, game);
	if (game->map->p != 1)
		message_error(EXIT_MISSING_P, game);
	if (game->map->c < 1)
		message_error(EXIT_MISSING_C, game);
}

void	validate_map(char *file, t_game *game)
{
	char	*lines;
	char	*temp;
	char	*aux;
	int		fd;

	lines = ft_strdup("");
	if (!(ft_strnstr(file, ".ber", ft_strlen(file))))
		message_error(EXIT_INVALID_FILE, game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		message_error(EXIT_INVALID_FILE, game);
	while (1)
	{
		aux = get_next_line(fd);
		if (aux == NULL)
			break ;
		temp = ft_strjoin(lines, aux);
		free(aux);
		free(lines);
		lines = temp;
	}
	close(fd);
	game->map->map = ft_split(lines, '\n');
	free(lines);
	parse_map(game);
}
