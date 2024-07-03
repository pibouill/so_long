/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:19:11 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/03 14:55:07 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_flood_fill(t_map *map, int player_i, int player_j, bool **visited)
{
}

void	get_exit_pos_and_c_count(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->array[j])
	{
		i = 0;
		while (map->array[j][i])
		{
			if (map->array[j][i] == 'E')
			{
				map->exit_i = i;
				map->exit_j = j;
			}
			if (map->array[j][i] == 'C')
				map->coin_amount++;
			i++;
		}
		j++;
	}
}

void	get_player_pos(t_map *map, int row, int *player_i, int *player_j)
{
	int	i;

	i = 0;
	while (map->array[row][i])
	{
		if (map->array[row][i] == 'P')
		{
			*player_i = i;
			*player_j = j;
			break ;
		}
		i++;
	}
}

void	map_path_check(t_map *map)
{
	int		j;
	int		player_j;
	int		player_i;
	bool	**visited;

	visited = ft_calloc(map->height, sizeof(bool *));
	j = 0;
	while (j < map->height)
		visited[j++] = ft_calloc(map->width, sizeof(bool *));
	j = 0;
	while (map->array[j])
	{
		map->p_pos = get_player_pos(map, j, &player_i, &player_j);
		j++;
	}
	get_exit_pos_and_c_count(map);
	do_flood_fill(map, player_i, player_j, visited);





}
