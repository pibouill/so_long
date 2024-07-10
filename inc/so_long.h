/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:27:13 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/10 12:57:41 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <math.h>
# include <MLX42.h>
# include <libft.h>

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define UP_RATIO 42

# define RED   "\x1B[31m"
# define GREEN   "\x1B[32m"
# define YELLOW   "\x1B[33m"
# define BLUE   "\x1B[34m"
# define MAGEN   "\x1B[35m"
# define RESET "\x1B[0m"

typedef struct s_asset
{
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*open_door;
	mlx_image_t	*close_door;
	mlx_image_t	*coin;
}			t_asset;

typedef struct s_map
{
	mlx_t	*mlx;
	t_asset	asset;
	char	**array;
	char	*map_name;
	int		width;
	int		height;
	int		x;
	int		y;
	int		c_flag;
	int		p_flag;
	int		e_flag;
	int		exit_i;
	int		exit_j;
	int		player_i;
	int		player_j;
	int		coin_amount;
	int		coin_check;
	int		screen_w;
	int		screen_h;
	int		score;
	int		moves;
}				t_map;

void	args_check(int ac, char **av, t_map *map);
int		count_width(const char *s, char c);
void	build_map_array(t_map *map);
void	get_map_size(t_map *map);
void	hook(void *param);
void	map_check(t_map *map);
bool	is_valid_path(t_map *map);

void	update_player(int i, int j, t_map *map);
void	update_door(t_map *map);
void	player_movement(t_map *map);
void	my_keyhook(mlx_key_data_t keydata, void *param);

void	img_to_map(t_map *map);
void	load_assets(t_map *map);

void	finish_game(t_map *map);

// moves
void	move_right(int i, int j, t_map *map);
void	move_left(int i, int j, t_map *map);
void	move_down(int i, int j, t_map *map);
void	move_up(int i, int j, t_map *map);

// error utils
void	error_free_exit(char *error_mess, t_map *map);
void	empty_line_free_exit(char *line, char *tot_line, char *mess);

// free utils
void	free_split(char **arr);
void	free_map_array(t_map *map);
void	free_visited(bool **visited, int map_height);

#endif
