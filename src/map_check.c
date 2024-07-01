/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:45:03 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/01 17:42:28 by pibouill         ###   ########.fr       */
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
		if (line[i] == '\n')
			return (width);
		i++;
	}
	return (width);
}

static bool	is_good_top_and_bot_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->array)
	{
		if (map->array[0][i++] != '1')
			return (false);
		i = 0;
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
	while (map->array[j++][i] && j <= map->height - 1)
	{
		if (map->array[j][0] != '1')
			return (false);
		if (map->array[j][map->width - 1] != '1')
			return (false);
		i = 0;
		while (i <= map->width - 1)
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
	int	i;
	int	j;


	i = 0;
	j = 0;
	/*printf("first line: %s\n", map->array[3]);*/
	line_length = get_line_width(map->array[0]);
	printf("%d\n", line_length);
	return (false);
}

void	map_check(t_map *map)
{
	if (is_lines_all_same_length(map) == false)
		return (ft_printf_fd(2, "Lines aren't the same length\n"),
				exit(EXIT_FAILURE));
	if (is_good_top_and_bot_walls(map) == false)
		return (ft_printf_fd(2, "Invalid top and bot walls\n"),
				exit(EXIT_FAILURE));
	if (is_good_inside_chars(map) == false)
		return (ft_printf_fd(2, "Map chars error\n"),
				exit(EXIT_FAILURE));
	if (map->c_flag < 1 || map->e_flag != 1 || map->p_flag != 1)
		return (ft_printf_fd(2, "Map chars error\n"),
				exit(EXIT_FAILURE));
	printf("GOOOOOOD MAP\n");
}
