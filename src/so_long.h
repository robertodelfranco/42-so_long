/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:17:28 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/02/17 15:46:02 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../current_lib/Includes/get_next_line_bonus.h"
# include "../current_lib/Includes/ft_printf_bonus.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../current_lib/Includes/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

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
# define EXIT_NO_PATH -11
# define EXIT_MAP_NOT_CLOSED -12

typedef struct s_dead
{
	mlx_texture_t	*dead_text[5];
	mlx_image_t		*dead_img[5];
	mlx_image_t		*current_img;
	double			frame_delay;
	double			move_time;
}			t_dead;

typedef struct s_enemie
{
	mlx_texture_t	*frames_text[6];
	mlx_image_t		*frames_img[6];
	mlx_image_t		*current_img;
	int				e;
	int				pos_x;
	int				pos_y;
	double			move_delay;
	double			move_time;
}			t_enemie;
typedef struct s_player
{
	mlx_texture_t	*frames_text[6];
	mlx_image_t		*frames_img[6];
	mlx_image_t		*current_img;
	int				current_frame;
	int				total_frames;
	int				pos_x;
	int				pos_y;
	double			frame_move_delay;
	double			frame_time;
	double			move_delay;
	double			move_time;
}		t_player;

typedef struct s_map
{
	char		**map;
	char		**map_copy;
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
	mlx_texture_t	*ribbon_text;
	mlx_image_t		*ribbon_img;
	mlx_texture_t	*game_over_text;
	mlx_image_t		*game_over_img;
	mlx_texture_t	*phrase_game_over_text;
	mlx_image_t		*phrase_game_over_img;
}		t_image;

typedef struct s_game
{
	void		*mlx;
	char		*file;
	t_map		*map;
	t_image		*img;
	t_player	*player;
	t_enemie	*enemie;
	t_dead		*dead;
	int			enemie_flag;
	int			game_over_flag;
}		t_game;

// validate //
void	parse_map(t_game *game);
void	verify_map(t_game *game);
bool	check_line_size(t_game *game);
int		is_closed(t_game *game, int i, int j);
void	validate_map(char *file, t_game *game);

// errors //
void	message_error(short error_code, t_game *game);
void	free_and_close_error(t_game *game, short error_code);
void	ft_free(char **ptr_matrix, int j);
void	free_file(t_game *game);

// init //
void	init_map(t_map *map);
void	init_images(t_game *game);
void	init_program(t_game *game);
void	init_images_again(t_game *game);
void	init_images_once_again(t_game *game);

// player //
void	ft_player(void *param);
void	update_frame(t_game *game, double delta_time);
void	main_move(mlx_key_data_t keydata, void *param);
void	set_hooks(mlx_key_data_t keydata, t_game *game, double delta_time);
void	move_player(t_game *game, int move_x, int move_y, t_player *player);

// utils //
int		ft_abs(int n);
double	get_delta_time(void);
double	get_delta_time_again(void);
void	set_exit_position(t_game *game, int i, int j);
void	set_player_position(t_game *game, int i, int j);

// window_images //
void	map_restore(t_game *game);
void	render_player(t_game *game);
void	put_images_in_window(t_game *game);
void	put_wall(t_game *game, int i, int j);
void	put_exits(t_game *game, int i, int j);

// handle_cases //
void	ft_handle_final_exit(t_game *game);
void	ft_handle_exit(t_game *game, int x, int y);
void	ft_handle_common_move(t_game *game, int x, int y);
void	ft_handle_collectable(t_game *game, int x, int y);
void	ft_handle_last_collectable(t_game *game, int x, int y);

// handle_decorations //
void	put_mushroons(t_game *game, mlx_image_t *mushroom_img);
void	ft_handle_tree(t_game *game, int move_x, int move_y);
void	put_tree(t_game *game, int i, int j, int *flag);
void	mushroom_rand(t_game *game, int i, int flag);
void	find_tile(t_game *game);

// animations //
void	load_dead_images(t_game *game);
void	load_animate_images(t_game *game);
void	update_dead(t_game *game, double delta_time);

// enemie //
void	ft_handle_enemie(t_game *game);
void	load_enemie_animation(t_game *game);
void	update_enemy(t_game *game, double delta_time);
void	set_enemie_position(t_game *game, int i, int j);

// flood_fill //
void	copy_map(t_game *game);
void	verify_flood_fill(t_game *game);
void	flood_fill(t_game *game, int x, int y);

// clear_mlx //
void	delete_images(t_game *game);
void	free_and_close(t_game *game);
void	free_animate_images(t_game *game);

#endif /* SO_LONG_H */
