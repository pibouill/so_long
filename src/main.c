/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:37 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/09 16:06:15 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_map *map)
{
	map->array = NULL;
	map->width = 0;
	map->height = 0;
	map->x = 0;
	map->y = 0;
	map->c_flag = 0;
	map->p_flag = 0;
	map->e_flag = 0;
	map->exit_i = 0;
	map->exit_j = 0;
	map->coin_amount = 0;
	map->coin_check = 0;
	map->moves = 0;
	map->score = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	args_check(ac, av, &map);
	init_struct(&map);
	get_map_size(&map);
	build_map_array(&map);
	map_check(&map);
	if (is_valid_path(&map) == false)
		error_free_exit("Error\nInvalid Path", &map);
	map.screen_w = map.width * UP_RATIO;
	map.screen_h = map.height * UP_RATIO;
	map.mlx = mlx_init(map.screen_w, map.screen_h, "so_long", true);
	if (map.mlx == NULL)
		error_free_exit("mlx error", &map);
	img_to_map(&map);
	mlx_key_hook(map.mlx, &my_keyhook, &map);
	mlx_loop(map.mlx);
	/*free_map_array(&map);*/
	mlx_terminate(map.mlx);
}
