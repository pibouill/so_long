/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:45:03 by pibouill          #+#    #+#             */
/*   Updated: 2024/06/26 14:41:53 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_line_width(char *line)
{
	int	width;

	width = count_width(line, ' ');
	return (width);
}

bool	is_good_top_wall(t_map *map);
bool	is_good_side_walls(t_map *map);
bool	is_good_bottom_wall(t_map *map);

bool	is_good_chars(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (map->array[j][i] == '1')
		i++;
	j++;
	while (map->array[j][i])
	{
		i = 0;
		if (map->array[j][0] != '1' || map->array[j][map->width - 1] != '1')
			return false;
		if (map->array[j][i] == 'P' || map->array[j][i] == 'E' || map->array[j][i] == 'C')
			i++;
		else
			return false;
		j++;
	}
	i = 0;
	while (map->array[j][i] == '1')
		i++;
	return true;
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
