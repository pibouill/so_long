/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:27:13 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/03 16:10:34 by pibouill         ###   ########.fr       */
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

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 720

# define RED   "\x1B[31m"
# define GREEN   "\x1B[32m"
# define YELLOW   "\x1B[33m"
# define BLUE   "\x1B[34m"
# define MAGEN   "\x1B[35m"
# define RESET "\x1B[0m"

# define MLX_WHITE 0xFFFFFFFF
# define MLX_BLACK 0x000000FF
/*# define GREEN  "\e[38;5;118m"
# define YELLOW	"\e[38;5;226m"
# define BLUE	"\e[38;5;27m"
# define RED	"\e[38;5;196m"
# define ORANGE	"\e[38;5;208m"
# define PURPLE	"\e[38;5;93m"
# define RESET	"\e[0m"*/


typedef struct s_map
{
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
	int		coin_amount;
	int		coin_check;
}				t_map;

bool	is_ber_file(char *filename);
int		count_width(const char *s, char c);
void	build_map_array(t_map *map);
void	get_map_size(t_map *map);
void	hook(void *param);
void	draw_background(mlx_image_t *img);
void	map_check(t_map *map);
bool	is_valid_path(t_map *map);


// error utils
void	error_free_exit(char *error_mess, t_map *map);
void	empty_line_free_exit(char *line, char *tot_line, char *mess);

// free utils
void	free_split(char **arr);
void	free_map_array(t_map *map);
void	free_visited(bool **visited, int map_height);

#endif
