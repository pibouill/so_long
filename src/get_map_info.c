/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:38:04 by pibouill          #+#    #+#             */
/*   Updated: 2024/06/26 12:55:12 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_height(char *filename)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(2, RED "Error opening file in get_map_height()\n" RESET);
		exit(EXIT_FAILURE);
	}
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			close(fd);
			return (height);
		}
		/*printf("map read-> %s", line);*/
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

int	get_map_width(char *filename)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(2, RED "Error opening file in get_map_width()\n" RESET);
		exit(EXIT_FAILURE);
	}
	width = 0;
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (width);
	}
	width = count_width(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	get_map_size(t_map *map)
{
	map->width = get_map_width(map->map_name);
	map->height = get_map_height(map->map_name);
	if (map->width <= 1 || map->height <= 1)
	{
		ft_printf_fd(2, RED "Map too small.\n" RESET);
		exit(EXIT_FAILURE);
	}
	if (is_lines_all_same_length(map) == false)
	{
		ft_printf_fd(2, RED "Invalid map.\nNot a rectangle.\n" RESET);
		exit(EXIT_FAILURE);
	}
	if (is_good_chars(map) == false)
	{
		ft_printf_fd(2, RED "Invalid map.\nChars not good.\n" RESET);
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("Gud mop\n");
}
