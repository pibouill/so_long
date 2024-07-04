/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:38:04 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/04 12:00:55 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_height(char *filename)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(2, RED "Error\nFile probably doesn't exist\n" RESET);
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
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

static int	get_map_width(char *filename)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(2, RED "Error\nFile probably doesn't exist\n" RESET);
		exit(EXIT_FAILURE);
	}
	width = 0;
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		ft_printf_fd(2, RED "Error\nEmpty map\n" RESET);
		exit(EXIT_FAILURE);
	}
	while (line[width])
		width++;
	free(line);
	close(fd);
	return (width - 1);
}

static void	nl_check(char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (*line == '\n')
	{
		close(fd);
		free(line);
		ft_printf_fd(2, RED "Error\nEmpty first line\n" RESET);
		exit(EXIT_FAILURE);
	}
	free(line);
	return ;
}

void	get_map_size(t_map *map)
{
	map->width = get_map_width(map->map_name);
	map->height = get_map_height(map->map_name);
	nl_check(map->map_name);
	if (map->width < 5 || map->height < 3)
	{
		ft_printf_fd(2, RED "Error\nMap too small.\n" RESET);
		exit(EXIT_FAILURE);
	}
}
