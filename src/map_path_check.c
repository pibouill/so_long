/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:19:11 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/08 19:14:46 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_valid_move(t_map *map, bool **visited, int j, int i)
{
	if (map->array[j][i] == '1')
		return (false);
	if (visited[j][i] == false)
		return (true);
	return (false);
}

static void	do_flood_fill(t_map *map, int i, int j, bool **visited)
{
	if ((is_valid_move(map, visited, j, i) == false) || (visited[j][i] == true))
		return ;
	if (map->array[j][i] == 'C')
		map->coin_check++;
	/*Door can or can't block coins*/
	if (map->array[j][i] == 'E' && map->coin_amount != map->coin_check)
		return ;
	visited[j][i] = true;
	do_flood_fill(map, i - 1, j, visited);
	do_flood_fill(map, i + 1, j, visited);
	do_flood_fill(map, i, j - 1, visited);
	do_flood_fill(map, i, j + 1, visited);
}

static void	get_exit_pos_and_c_count(t_map *map)
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

static void	get_player_pos(t_map *map, int row, int *player_i, int *player_j)
{
	int	i;

	i = 0;
	while (map->array[row][i])
	{
		if (map->array[row][i] == 'P')
		{
			*player_i = i;
			*player_j = row;
			map->player_i = i;
			map->player_j = row;
			break ;
		}
		i++;
	}
}

bool	is_valid_path(t_map *map)
{
	int		j;
	int		player_j;
	int		player_i;
	bool	**visited;
	bool	valid_path;

	valid_path = false;
	visited = ft_calloc(map->height, sizeof(bool *));
	j = 0;
	while (j < map->height)
		visited[j++] = ft_calloc(map->width, sizeof(bool *));
	j = -1;
	while (map->array[++j])
		get_player_pos(map, j, &player_i, &player_j);
	get_exit_pos_and_c_count(map);
	do_flood_fill(map, player_i, player_j, visited);
	if (visited[player_j][player_i] && visited[map->exit_j][map->exit_i])
		valid_path = true;
	free_visited(visited, map->height);
	if (map->coin_amount != map->coin_check || valid_path == false)
		return (false);
	printf(GREEN"valid map gg\n"RESET);
	return (true);
}
