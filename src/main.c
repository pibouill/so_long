/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:37 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/08 15:06:10 by pibouill         ###   ########.fr       */
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

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long (map).ber\n");
		exit(EXIT_FAILURE);
	}
	map.map_name = av[1];
	if (is_ber_file(map.map_name) == false)
		return (1);
	init_struct(&map);
	get_map_size(&map);
	build_map_array(&map);
	printf("\nmap height: %d\n", map.height);
	printf("map width: %d\n", map.width);
	map_check(&map);
	if (is_valid_path(&map) == false)
		error_free_exit("Error\nInvalid Path", &map);
	printf("coin_amount: %d\n", map.coin_amount);
	map.screen_w = map.width * UP_RATIO;
	map.screen_h = map.height * UP_RATIO;
	map.mlx = mlx_init(map.screen_w, map.screen_h, "so_long", true);
	if (map.mlx == NULL)
		exit(EXIT_FAILURE);
	printf("player pos %d | %d\n", map.player_j, map.player_i);
	mlx_loop_hook(map.mlx, &hook, &map);
	mlx_key_hook(map.mlx, &my_keyhook, &map);
	mlx_loop(map.mlx);
	free_map_array(&map);
	mlx_terminate(map.mlx);
	return (0);
}
