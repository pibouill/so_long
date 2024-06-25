/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:32:46 by pibouill          #+#    #+#             */
/*   Updated: 2024/05/30 16:36:38 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_iso(int x, int y, int z)
{
	int	previous_x;
	int	previous_y;

	x = (previous_x - previous_y) * cos(30DEG_RAD);
	y = -z + (previous_x + previous_y) * sin(30DEG_RAD);
}
