/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:34:11 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/08 20:16:54 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	int		i;
	int		j;
	t_map	*map;

	map = param;
	i = map->player_i;
	j = map->player_j;
	if (map->coin_amount == map->score)
		update_door(map);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			finish_game(map);
		if (keydata.key == MLX_KEY_W && map->array[j - 1][i] != '1')
			move_up(i, j, map);
		if (keydata.key == MLX_KEY_S && map->array[j + 1][i] != '1')
			move_down(i, j, map);
		if (keydata.key == MLX_KEY_D && map->array[j][i + 1] != '1')
			move_right(i, j, map);
		if (keydata.key == MLX_KEY_A && map->array[j][i - 1] != '1')
			move_left(i, j, map);
	}
}
