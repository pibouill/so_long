/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:45:03 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/02 15:19:57 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_line_width(char *line)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
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
		if (map->array[0][i++] != '1')
			return (false);
	}
	i = 0;
	while (i < map->width)
	{
		if (map->array[map->height - 1][i++] != '1')
			return (false);
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
		if (map->array[j][0] != '1')
			return (false);
		if (map->array[j][map->width - 1] != '1')
			return (false);
		i = 0;
		while (i < map->width)
		{
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
	line_length = get_line_width(map->array[0]);
	while (j < map->height)
	{
		if (line_length != get_line_width(map->array[j]))
			return (false);
		j++;
	}
	return (true);
}

void	map_check(t_map *map)
{
	if (is_lines_all_same_length(map) == false)
		return (error_free_exit("Map format issue", map));
	if (is_good_top_and_bot_walls(map) == false)
		return (error_free_exit("Invalid top and/or bot walls", map));
	if (is_good_inside_chars(map) == false)
		return (error_free_exit("Map chars error", map));
	if (map->c_flag < 1)
		return (error_free_exit("Not enough collectibles 'C'", map));
	if (map->e_flag != 1)
		return (error_free_exit("Invalid number of E's", map));
	if (map->p_flag != 1)
		return (error_free_exit("Invalid number of P's", map));
	printf("GOOOOOOD MAP\n");
}
