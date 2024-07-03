/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:45:03 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/03 17:08:23 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_line_width(char *line, t_map *map)
{
	int	width;
	int	i;

	width = 0;
	(void)map;
	i = 0;
	if (line[i] == '\n' || line[i] == 0 || line == NULL)
		return (0);
	while (line[i])
	{
		i++;
		width++;
	}
	return (width);
}

static bool	is_good_top_and_bot_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->array[0][i] != '1' || map->array[map->height - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->array[i][0] != '1' || map->array[i][map->width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	is_good_inside_chars(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (++j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->array[j][i] != '0' &&
					map->array[j][i] != '1' && map->array[j][i] != 'C'
					&& map->array[j][i] != 'E' && map->array[j][i] != 'P')
				return (false);
			if (map->array[j][i] == 'C')
				map->c_flag += 1;
			if (map->array[j][i] == 'P')
				map->p_flag += 1;
			if (map->array[j][i] == 'E')
				map->e_flag += 1;
			i++;
		}
	}
	return (true);
}

static bool	is_lines_all_same_length(t_map *map)
{
	int	line_length;
	int	j;

	j = 1;
	line_length = get_line_width(map->array[0], map);
	while (j < map->height)
	{
		if (line_length == 0)
			return (error_free_exit("Error\nEmpty line", map), false);
		if (line_length != get_line_width(map->array[j], map))
			return (false);
		j++;
	}
	return (true);
}

void	map_check(t_map *map)
{
	if (is_lines_all_same_length(map) == false)
		return (error_free_exit("Error\nMap format issue", map));
	if (is_good_top_and_bot_walls(map) == false)
		return (error_free_exit("Error\nInvalid top and/or bot walls", map));
	if (is_good_inside_chars(map) == false)
		return (error_free_exit("Error\nInvalid map char(s)", map));
	if (map->c_flag < 1)
		return (error_free_exit("Error\nNot enough collectibles 'C'", map));
	if (map->e_flag != 1)
		return (error_free_exit("Error\nInvalid number of E's", map));
	if (map->p_flag != 1)
		return (error_free_exit("Error\nInvalid number of P's", map));
	printf("GOOOOOOD MAP\n");
}
