/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:11:32 by pibouill          #+#    #+#             */
/*   Updated: 2024/06/18 15:49:32 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static t_point	get_point(t_map *map, int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map->map_array[y][x];
	return (point);
}*/

/*void	get_points(t_map *map)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	map->points = malloc(map->height * map->width * (sizeof(t_point)));
	if (map->points == NULL)
		return ;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[i] = get_point(map, x, y);
			i++;
			x++;
		}
		y++;
	}
}*/
