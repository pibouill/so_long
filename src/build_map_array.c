/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:35:31 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/03 14:01:32 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			printf("[%c]", map->array[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

void	build_map_array(t_map *map)
{
	int		fd;
	char	*line;
	char	*total_line;

	fd = open(map->map_name, O_RDONLY);
	total_line = ft_strdup("");
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf_fd(2, RED "Empty file.\n" RESET),
			exit(EXIT_FAILURE));
	while (line)
	{
		if (line == NULL || *line == '\n')
			empty_line_free_exit(line, total_line, "Empty line");
		total_line = ft_strjoin(total_line, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map->array = ft_split(total_line, '\n');
	free(total_line);
	print_map(map);
}
