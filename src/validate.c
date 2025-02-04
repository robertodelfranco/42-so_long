/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:56:11 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/04 16:34:47 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_map(t_map *map)
{
	int i;
	int	j;

	i = -1;
	while (i++, map->map[i] != NULL)
	{
		j = -1;
		while (j++, map->map[i][j] != '\0' && map->map[i][j] != '\n')
		{
			if (map->map[i][j] == 'C')
				map->collectable++;
			if (map->map[i][j] == 'E')
				map->exit++;
			if (map->map[i][j] == 'P')
				map->player++;
		}
	}
	if (map->exit != 1 || map->player != 1 || map->collectable < 1)
		message_error(EXIT_INVALID_MAP);
}

void	validate_map(char *file, t_map *map)
{
	int		fd;
	int		i;

	if (!(ft_strnstr(file, ".ber", ft_strlen(file))))
		message_error(EXIT_INVALID_FILE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		message_error(EXIT_INVALID_FILE);
	i = 0;
	while (1)
	{
		map->map = my_realloc(map->map, sizeof(char *) * (i + 1));
		map->map[i] = get_next_line(fd);
		if (map->map[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	verify_map(map);
}
