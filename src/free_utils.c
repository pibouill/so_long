/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:19:57 by pibouill          #+#    #+#             */
/*   Updated: 2024/05/29 13:51:40 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		free(map->map_array[i++]);
	free(map->map_array);
}
