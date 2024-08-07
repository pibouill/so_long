/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:56:15 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/03 14:00:05 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_free_exit(char *error_mess, t_map *map)
{
	if (map)
	{
		free_map_array(map);
		ft_printf_fd(2, RED "%s\n" RESET, error_mess);
		exit(EXIT_FAILURE);
	}
}

void	empty_line_free_exit(char *line, char *tot_line, char *mess)
{
	free(line);
	free(tot_line);
	ft_printf_fd(2, RED "%s\n" RESET, mess);
	exit(EXIT_FAILURE);
}
