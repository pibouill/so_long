/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:35:31 by pibouill          #+#    #+#             */
/*   Updated: 2024/06/26 13:51:41 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	build_map_line(t_map *map, char **char_map)
{
	while (map->x < map->width)
	{
		map->map_array[map->y][map->x] = char_map[map->x];
		printf("[%c]", map->map_array[map->y][map->x]);
		/*free(char_map[map->x]);*/
		map->x++;
	}
}

void	build_map_array(t_map *map)
{
	int		fd;
	char	*line;
	char	**char_map;

	fd = open(map->map_name, O_RDONLY);
	map->map_array = malloc(sizeof(char *) * map->height);
	if (map->map_array == NULL)
		(ft_printf_fd(2, "Allocation error.\n"), exit(EXIT_FAILURE));
	while (map->y < map->height)
	{
		map->map_array[map->y] = malloc(sizeof(char) * map->width);
		if (map->map_array[map->y] == NULL)
			(ft_printf_fd(2, "Allocation error.\n"), exit(EXIT_FAILURE));
		line = get_next_line(fd);
		char_map = ft_split(line, ' ');
		free(line);
		map->x = 0;
		/*printf("\n");*/
		build_map_line(map, char_map);
		map->y++;
		is_good_chars(char_map);
		free_split(char_map);
	}
}
