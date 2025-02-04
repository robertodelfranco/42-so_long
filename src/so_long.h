/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:28 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/04 16:37:36 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../current_lib/Includes/get_next_line_bonus.h"
# include "../current_lib/Includes/ft_printf_bonus.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../current_lib/Includes/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		collectable;
	int		exit;
	int		movements;
}		t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_map	*map;
}		t_game;

# define EXIT_INVALID_FILE	-3
# define EXIT_INVALID_MAP 	-2
# define EXIT_INVALID_ARGS	-1
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

// so_long.c //
void	validate_map(char *file, t_map *map);


void	message_error(short error_code);

#endif /* SO_LONG_H */