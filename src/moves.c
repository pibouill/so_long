/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:25:33 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/08 13:01:36 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(int i, int j, t_map *map)
{
	if (map->array[j][i + 1] == 'C')
		map->score++;
	else if (map->array[j][i + 1] == 'E' && (map->score == map->coin_amount))
		finish_game(map);
	else if (map->array[j][i + 1] == 'E')
		return ;
	map->moves++;
	map->array[j][i] = '0';
	map->array[j][i + 1] = 'P';
	update_player(i + 1, j, map);
	mlx_image_to_window(map->mlx, map->asset.ground,
		x * UP_RATIO, y * UP_RATIO);
}

void	move_left(int i, int j, t_map *map)
{
	if (map->array[j][i - 1] == 'C')
		map->score++;
	else if (map->array[j][i - 1] == 'E' && (map->score == map->coin_amount))
		finish_game(map);
	else if (map->array[j][i - 1] == 'E')
		return ;
	map->moves++;
	map->array[j][i] = '0';
	map->array[j][i - 1] = 'P';
	update_player(i - 1, j, map);
	mlx_image_to_window(map->mlx, map->asset.ground,
		x * UP_RATIO, y * UP_RATIO);
}

void	move_up(int i, int j, t_map *map)
{
	if (map->array[j - 1][i] == 'C')
		map->score++;
	else if (map->array[j - 1][i] == 'E' && (map->score == map->coin_amount))
		finish_game(map);
	else if (map->array[j - 1][i] == 'E')
		return ;
	map->moves++;
	map->array[j][i] = '0';
	map->array[j - 1][i] = 'P';
	update_player(i , j - 1, map);
	mlx_image_to_window(map->mlx, map->asset.ground,
		x * UP_RATIO, y * UP_RATIO);
}

void	move_down(int i, int j, t_map *map)
{
	if (map->array[j + 1][i] == 'C')
		map->score++;
	else if (map->array[j + 1][i] == 'E' && (map->score == map->coin_amount))
		finish_game(map);
	else if (map->array[j + 1][i] == 'E')
		return ;
	map->moves++;
	map->array[j][i] = '0';
	map->array[j + 1][i] = 'P';
	update_player(i , j + 1, map);
	mlx_image_to_window(map->mlx, map->asset.ground,
		x * UP_RATIO, y * UP_RATIO);
}
