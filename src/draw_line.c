/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:52:40 by pibouill          #+#    #+#             */
/*   Updated: 2024/06/18 15:50:42 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	horizontal(int x0, int x1, int inc_x, int y0, mlx_image_t *img)
{
	int	x;

	x = x0;
	while (x != x1 + inc_x)
	{
		mlx_put_pixel(img, x, y0, MLX_WHITE);
		x += inc_x;
	}
}

static void	vertical(int y0, int y1, int inc_y, int x0, mlx_image_t *img)
{
	int	y;

	y = y0;
	while (y != y1 + inc_y)
	{
		mlx_put_pixel(img, x0, y, MLX_WHITE);
		y += inc_y;
	}
}

static void	more_horz_than_vert(t_line_data *line_data, t_point *curr, t_point *next, mlx_image_t *img)
{
	int	slope;
	int	error;
	int	error_inc;
	int	y;
	int	x;

	slope = 2 * line_data->dy;
	error = -(line_data->dx);
	error_inc = -2 * line_data->dx;
	y = curr->y;
	x = curr->x;
	while (x != next->x + line_data->inc_x)
	{
		mlx_put_pixel(img, x, y, MLX_WHITE);
		error += slope;
		if (error >= 0)
		{
			y += line_data->inc_y;
			error += error_inc;
		}
		x += line_data->inc_x;
	}
}

static void	more_vert_than_horz(t_line_data *line_data, t_point *curr, t_point *next, mlx_image_t *img)
{
	int	slope;
	int	error;
	int	error_inc;
	int	y;
	int	x;

	slope = 2 * line_data->dx;
	error = -(line_data->dy);
	error_inc = -2 * line_data->dy;
	y = curr->y;
	x = curr->x;
	while (y != next->y + line_data->inc_y)
	{
		mlx_put_pixel(img, x, y, MLX_WHITE);
		error += slope;
		if (error >= 0)
		{
			x += line_data->inc_x;
			error += error_inc;
		}
		y += line_data->inc_y;
	}
}

void	draw_line(t_point curr, t_point next, mlx_image_t *img)
{
	t_line_data	line_data;

	line_data.dx = ABS(next.x - curr.x);
	line_data.dy = ABS(next.y - curr.y);
	line_data.inc_x = SGN(line_data.dx);
	line_data.inc_y = SGN(line_data.dy);
	printf("line_data.dx = %d\n", line_data.dx);
	printf("line_data.dy = %d\n", line_data.dy);
	printf("line_data.inc_x = %d\n", line_data.inc_x);
	printf("line_data.inc_y = %d\n", line_data.inc_y);
	if (line_data.dy == 0)
		horizontal(curr.x, next.x, curr.y, line_data.inc_x, img);
	else if (line_data.dx == 0)
		vertical(curr.y, next.y, curr.x, line_data.inc_y, img);
	else if (line_data.dx >= line_data.dy)
		more_horz_than_vert(&line_data, &curr, &next, img);
	else
		more_vert_than_horz(&line_data, &curr, &next, img);
}
