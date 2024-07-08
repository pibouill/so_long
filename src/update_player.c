/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:38:01 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/08 20:21:59 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(int i, int j, t_map *map)
{
	mlx_image_to_window(map->mlx, map->asset.player,
		i * UP_RATIO + 10, j * UP_RATIO + 2);
	map->player_i = i;
	map->player_j = j;
}

void	update_door(t_map *map)
{
	mlx_delete_image(map->mlx, map->asset.close_door);
	mlx_image_to_window(map->mlx, map->asset.open_door,
		map->exit_i * UP_RATIO + 7, map->exit_j * UP_RATIO - 1);
}
