/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:35:31 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/01 17:43:37 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*static void	build_map_line(t_map *map, char *line)*/
/*{*/
	/*int	i;*/

	/*i = 0;*/
	/*printf("blue\n");*/
	/*while (line[i] && i < map->width)*/
	/*{*/
		/*map->array[map->y][i] = line[i];*/
		/*i++;*/
	/*}*/
/*}*/

void	build_map_array(t_map *map)
{
	int		fd;
	char	*line;
	char	*total_line;
	char	*tmp;

	fd = open(map->map_name, O_RDONLY);
	total_line = ft_strdup("");
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf_fd(2, RED "Empty file.\n" RESET),
			   exit(EXIT_FAILURE));
	while (line)
	{
		tmp = ft_strjoin(total_line, line);
		/*free(total_line);*/
		total_line = tmp;
		printf("%s\n", total_line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	free(tmp);
	close(fd);
	map->array = ft_split(total_line, '\n');
	printf("bla: %s\n", map->array[0]);
	/*print_map(map);*/
}
