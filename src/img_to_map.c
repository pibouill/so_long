/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:49:08 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/08 18:16:00 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_check(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(2, RED "Error openning img\n" RESET);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

static void	img_to_window(t_map *map, int x, int y)
{
	if (x != 0 || y != 0)
		mlx_image_to_window(map->mlx, map->asset.ground,
			x * UP_RATIO, y * UP_RATIO);
	if (map->array[y][x] == '1')
		mlx_image_to_window(map->mlx, map->asset.wall,
			x * UP_RATIO, y * UP_RATIO);
	else if (map->array[y][x] == 'E')
		mlx_image_to_window(map->mlx, map->asset.door,
			x * UP_RATIO + 7, y * UP_RATIO - 1);
	else if (map->array[y][x] == 'P')
		mlx_image_to_window(map->mlx, map->asset.player,
			(x * UP_RATIO) + 10, (y * UP_RATIO) + 2);
	else if (map->array[y][x] == 'C')
		mlx_image_to_window(map->mlx, map->asset.coin,
			(x * UP_RATIO) + 13, (y * UP_RATIO) + 10);
	if (x == 0 && y == 0)
		mlx_image_to_window(map->mlx, map->asset.ground,
				x * UP_RATIO, y * UP_RATIO);
}

static mlx_image_t	*asset_to_img(mlx_t *mlx, char *path_to_img)
{
	xpm_t			*xpm;
	mlx_image_t		*img;
	mlx_texture_t	texture;

	open_check(path_to_img);
	xpm = mlx_load_xpm42(path_to_img);
	if (!xpm)
		ft_printf_fd(2, "Error loading xpm\n");
	texture = xpm->texture;
	img = mlx_texture_to_image(mlx, &texture);
	if (!img)
		ft_printf_fd(2, "Error loading texture\n");
	mlx_delete_xpm42(xpm);
	return (img);
}

static void	load_assets(t_map *map)
{
	map->asset.ground = asset_to_img(map->mlx,
			"./assets/xpm42/ground.xpm42");
	map->asset.wall = asset_to_img(map->mlx,
			"./assets/xpm42/wall.xpm42");
	map->asset.player = asset_to_img(map->mlx,
			"./assets/xpm42/player_125.xpm42");
	map->asset.coin = asset_to_img(map->mlx,
			"./assets/xpm42/coin.xpm42");
	if (map->coin_amount == map->score)
		map->asset.door = asset_to_img(map->mlx,
				"./assets/xpm42/open_door.xpm42");
	else
		map->asset.door = asset_to_img(map->mlx,
				"./assets/xpm42/close_door.xpm42");
}

void	img_to_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	load_assets(map);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			img_to_window(map, x, y);
			x++;
		}
		y++;
	}
	/*check win*/
}
			
