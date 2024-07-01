/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:35:31 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/01 13:46:21 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	build_map_line(t_map *map, char *line)
{
	int	i;

	i = 0;
	printf("blue\n");
	while (line[i] && i < map->width)
	{
		map->array[map->y][i] = line[i];
		i++;
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
	char_map = NULL;
	while (map->y < map->height)
	{
		map->array[map->y] = malloc(sizeof(char) * map->width);
		if (map->array[map->y] == NULL)
			(ft_printf_fd(2, "Allocation error.\n"), exit(EXIT_FAILURE));
		line = get_next_line(fd);
		/*build_map_line(map, char_map, line);*/
		map->x = 0;
		build_map_line(map, line);
		/*char_map = ft_split(line, '\n');*/
		free(line);
		map->y++;
		/*free_split(char_map);*/
	}
	close(fd);
}
