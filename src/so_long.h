/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:28 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/10 19:27:20 by rdel-fra         ###   ########.fr       */
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
# include <math.h>

# define WIDTH_WINDOW 640
# define HEIGHT_WINDOW 480
# define TILE 64

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
	mlx_texture_t	*player_text;
	mlx_image_t		*player_img;
	int				pos_x;
	int				pos_y;
}		t_player;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			p;
	int			c;
	int			e;
	int			pos_x_e;
	int			pos_y_e;
	int			moves;
}		t_map;

typedef struct s_image
{
	mlx_texture_t	*floor_text;
	mlx_image_t		*floor_img;
	mlx_texture_t	*wall_text;
	mlx_image_t		*wall_img;
	mlx_texture_t	*low_w_text;
	mlx_image_t		*low_w_img;
	mlx_texture_t	*exit_text;
	mlx_image_t		*exit_img;
	mlx_texture_t	*final_exit_text;
	mlx_image_t		*final_exit_img;
	mlx_texture_t	*collectable_text;
	mlx_image_t		*collectable_img;
	mlx_texture_t	*mushroom_text;
	mlx_image_t		*mushroom_img;
	mlx_texture_t	*tree_text;
	mlx_image_t		*tree_img;
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
void	ft_clear_window(t_game *game);
void	free_and_close(t_game *game);

// init //
void	init_map(t_map *map);
void	init_images(t_game *game);
void	init_program(t_game *game);
void	init_images_again(t_game *game);

// player //
void	ft_player(void *param);
void	set_hooks(mlx_key_data_t keydata, void *param);
void	move_player(t_game *game, int move_x, int move_y, t_player *player);

// utils //
void	set_exit_position(t_game *game, int i, int j);
void	set_player_position(t_game *game, int i, int j);

// window_images //
void	put_images_in_window(void *param);
void	put_mushroons(t_game *game);
void	find_tile(t_game *game);

// handle_cases //
void	ft_handle_exit(t_game *game, int x, int y);
void	ft_handle_final_exit(t_game *game, int x, int y);
void	ft_handle_common_move(t_game *game, int x, int y);
void	ft_handle_collectable(t_game *game, int x, int y);
void	ft_handle_last_collectable(t_game *game, int x, int y);

// handle_decorations //
void	ft_handle_tree(t_game *game, int move_x, int move_y);

#endif /* SO_LONG_H */
