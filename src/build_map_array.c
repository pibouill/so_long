/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:35:31 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/02 14:52:16 by pibouill         ###   ########.fr       */
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

void	print_map(t_map *map)
{
	int	i = 0;
	int	j = 0;

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
	/*char	*tmp;*/

	fd = open(map->map_name, O_RDONLY);
	total_line = ft_strdup("");
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf_fd(2, RED "Empty file.\n" RESET),
			   exit(EXIT_FAILURE));
	while (line)
	{
		/*tmp = ft_strjoin(total_line, line);*/
		total_line = ft_strjoin(total_line, line);
		/*free(total_line);*/
		/*total_line = tmp;*/
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	/*free(tmp);*/
	close(fd);
	if (map->array)
		free_map_array(map);
	map->array = ft_split(total_line, '\n');
	free(total_line);
	print_map(map);
}
