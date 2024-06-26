/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:45:03 by pibouill          #+#    #+#             */
/*   Updated: 2024/06/26 12:55:14 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line_width(char *line)
{
	int	width;

	width = count_width(line, ' ');
	return (width);
}

bool	is_good_top_wall(t_map *map);
bool	is_good_side_walls(t_map *map);
bool	is_good_bottom_wall(t_map *map);

bool	is_good_chars(char **char_map)
{
	/*int		c_flag;*/
	/*int		e_flag;*/
	/*int		p_flag;*/
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (char_map[j][i])
	{
		while (char_map[j][i] == '1')
			i++;
		j++;
		

}

bool	is_lines_all_same_length(t_map *map)
{
	char	*line;
	int		fd;

	fd = open(map->map_name, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			close(fd);
			break ;
		}
		if (get_line_width(line) != map->width)
		{
			ft_printf_fd(2, RED "Error. Incorrect map format\n" RESET);
			return (free(line), false);
		}
		free(line);
	}
	return (close(fd), true);
}
