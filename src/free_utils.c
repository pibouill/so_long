/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:19:57 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/08 13:27:03 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **split_res)
{
	int	i;

	i = 0;
	while (split_res[i])
		free(split_res[i++]);
	free(split_res);
}

void	free_map_array(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->array[i++]);
	free(map->array);
}

void	free_visited(bool **visited, int map_height)
{
	int	i;

	i = 0;
	while (i < map_height)
		free(visited[i++]);
	free(visited);
}

void	finish_game(t_map *map)
{
	free_map_array(map);
	mlx_terminate(map->mlx);
	ft_printf("Game finished gg\n");
	exit(EXIT_SUCCESS);
}
