/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:37 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/01 12:51:58 by pibouill         ###   ########.fr       */
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
}

int	main(int ac, char **av)
{
	t_map	map;
	mlx_t	*mlx;
	mlx_image_t	*img;


	/*args_check(ac, av);*/
	if (ac != 2)
	{
		ft_printf("Usage: <exec> <map>.ber\n");
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
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "so_long", true);
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	draw_background(img);
	printf("x = %d\ny = %d\n", map.x, map.y);
	mlx_loop_hook(mlx, hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_map_array(&map);
	return (0);
}
