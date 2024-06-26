/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:35:31 by pibouill          #+#    #+#             */
/*   Updated: 2024/06/26 14:45:11 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	build_map_line(t_map *map, char **char_map)
{
	while (map->x < map->width)
	{
		map->array[map->y][map->x] = *char_map[map->x];
		printf("[%c]", map->array[map->y][map->x]);
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
	map->array = malloc(sizeof(char *) * map->height);
	if (map->array == NULL)
		(ft_printf_fd(2, "Allocation error.\n"), exit(EXIT_FAILURE));
	while (map->y < map->height)
	{
		map->array[map->y] = malloc(sizeof(char) * map->width);
		if (map->array[map->y] == NULL)
			(ft_printf_fd(2, "Allocation error.\n"), exit(EXIT_FAILURE));
		line = get_next_line(fd);
		char_map = ft_split(line, ' ');
		free(line);
		map->x = 0;
		/*printf("\n");*/
		build_map_line(map, char_map);
		map->y++;
		free_split(char_map);
	}
}
