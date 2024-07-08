/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:34:11 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/08 13:05:03 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement(t_map *map)
{
	int	i;
	int	j;

	i = map->player_i;
	j = map->player_j;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		finish_game();
	else if ((mlx_is_key_down(map->mlx, MLX_KEY_S) || mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
			&& map->array[j + 1][i] != '1')
		move_down(i, j, map);
	else if ((mlx_is_key_down(map->mlx, MLX_KEY_W) || mlx_is_key_down(map->mlx, MLX_KEY_UP))
			&& map->array[j - 1][i] != '1')
		move_up(i, j, map);
	else if ((mlx_is_key_down(map->mlx, MLX_KEY_A) || mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
			&& map->array[j][i - 1] != '1')
		move_left(i, j, map);
	else if ((mlx_is_key_down(map->mlx, MLX_KEY_D) || mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
			&& map->array[j][i + 1] != '1')
		move_right(i, j, map);
}

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		finish_game();
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		move_up();
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	    move_down();
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	    move_left();
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	    move_right();
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	    move_up();
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	    move_down();
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	    move_left();
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		move_right();
}
