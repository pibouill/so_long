/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:45:03 by pibouill          #+#    #+#             */
/*   Updated: 2024/06/04 14:01:50 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line_width(char *line)
{
	int	width;

	width = count_width(line, ' ');
	return (width);
}

bool	is_valid_map(t_map *map)
{
	char	*line;
	int		fd;

	fd = open(map->map_name, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			close(fd);
			break ;
		}
		if (get_line_width(line) != map->width)
		{
			ft_printf_fd(2, RED "Error. Incorrect map format\n" RESET);
			return (free(line), false);
		}
		free(line);
	}
	return (close(fd), true);
}
