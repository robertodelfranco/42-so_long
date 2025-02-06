/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:28 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/06 11:43:36 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../current_lib/Includes/get_next_line_bonus.h"
# include "../current_lib/Includes/ft_printf_bonus.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../current_lib/Includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define EXIT_SUCCESS	0
# define EXIT_INVALID_FILE	-2
# define EXIT_INVALID_EXTENTION	-3
# define EXIT_INVALID_CHAR	-4
# define EXIT_MUST_BE_RECTANGULAR	-5
# define EXIT_TOO_SHORT	-6
# define EXIT_MISSING_E	-7
# define EXIT_MISSING_P	-8
# define EXIT_MISSING_C	-9
# define EXIT_LINE_SIZE -10

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			p;
	int			c;
	int			e;
	int			moves;
}		t_map;

typedef struct s_image
{
	mlx_texture_t	*floor_text;
	mlx_image_t		*floor_img;
	void	*wall;
	void	*player;
	void	*collectable;
	void	*exit;
}		t_image;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_image		*img;
	t_player	*player;
}		t_game;

// validate //
void	parse_map(t_game *game);
void	verify_map(t_game *game);
void	validate_map(char *file, t_game *game);

// errors //
void	message_error(short error_code, t_game *game);
void	ft_free(char **ptr_matrix, int j);
void	free_and_close(t_game *game);

// init //
void	init_map(t_map *map);
void	init_images(t_game *game);
void	init_program(t_game *game);

// window_images //
void	put_images_in_window(t_game *game);

#endif /* SO_LONG_H */