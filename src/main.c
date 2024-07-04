/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:37 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/04 15:51:24 by pibouill         ###   ########.fr       */
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
	is_valid_path(&map);
	printf("coin_amount: %d\n", map.coin_amount);
	map.screen_w = map.width * 64;
	map.screen_h = map.height * 64;
	map.mlx = mlx_init(map.width, map.height, "so_long", true);
	if (map.mlx == NULL)
		exit(EXIT_FAILURE);
	img_to_map(&map);
	/*img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);*/
	/*mlx_image_to_window(mlx, img, 0, 0);*/
	mlx_loop(map.mlx);
	free_map_array(&map);
	mlx_terminate(map.mlx);
	return (0);
}
