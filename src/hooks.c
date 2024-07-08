/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:34:11 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/08 18:24:21 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(void *param)
{
	t_map	*map;

	map = param;
	img_to_map(map);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	int		i;
	int		j;
	t_map	*map;

	map = param;
	i = map->player_i;
	j = map->player_j;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			finish_game(map);
		if (keydata.key == MLX_KEY_W && map->array[j - 1][i] != '1')
			move_up(i , j, map);
		if (keydata.key == MLX_KEY_S && map->array[j + 1][i] != '1')
			move_down(i, j, map);
		if (keydata.key == MLX_KEY_D && map->array[j][i + 1] != '1')
			move_right(i, j, map);
		if (keydata.key == MLX_KEY_A && map->array[j][i - 1] != '1')
			move_left(i, j, map);
	}
	/*if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))*/
		/*finish_game(map);*/
	/*else if ((mlx_is_key_down(map->mlx, MLX_KEY_S))*/
			/*&& map->array[j + 1][i] != '1')*/
		/*move_down(i, j, map);*/
	/*else if ((mlx_is_key_down(map->mlx, MLX_KEY_W))*/
			/*&& map->array[j - 1][i] != '1')*/
		/*move_up(i, j, map);*/
	/*else if ((mlx_is_key_down(map->mlx, MLX_KEY_A))*/
			/*&& map->array[j][i - 1] != '1')*/
		/*move_left(i, j, map);*/
	/*else if ((mlx_is_key_down(map->mlx, MLX_KEY_D))*/
			/*&& map->array[j][i + 1] != '1')*/
		/*move_right(i, j, map);*/
}

/*void	hook(void *param)*/
/*{*/
	/*mlx_t	*mlx;*/

	/*mlx = param;*/
	/*if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))*/
		/*finish_game();*/
	/*if (mlx_is_key_down(mlx, MLX_KEY_UP))*/
		/*move_up();*/
	/*if (mlx_is_key_down(mlx, MLX_KEY_DOWN))*/
		/*move_down();*/
	/*if (mlx_is_key_down(mlx, MLX_KEY_LEFT))*/
		/*move_left();*/
	/*if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))*/
		/*move_right();*/
	/*if (mlx_is_key_down(mlx, MLX_KEY_W))*/
		/*move_up();*/
	/*if (mlx_is_key_down(mlx, MLX_KEY_S))*/
		/*move_down();*/
	/*if (mlx_is_key_down(mlx, MLX_KEY_A))*/
		/*move_left();*/
	/*if (mlx_is_key_down(mlx, MLX_KEY_D))*/
		/*move_right();*/
/*}*/
