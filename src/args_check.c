/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:10:54 by pibouill          #+#    #+#             */
/*   Updated: 2024/07/09 13:39:26 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define INCORRECT_FILETYPE "Error\nIncorrect filetype.\nUse ber files only.\n"

static bool	is_ber_file(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i <= 4)
	{
		ft_printf_fd(2, RED INCORRECT_FILETYPE RESET);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(&filename[i - 4], ".ber", 4) == 0)
		return (true);
	return (false);
}

void	args_check(int ac, char **av, t_map *map)
{
	if (ac != 2)
	{
		ft_printf_fd(2, RED "Error\nUsage: ./so_long (map).ber\n" RESET);
		exit(EXIT_FAILURE);
	}
	map->map_name = av[1];
	if (is_ber_file(map->map_name) == false)
	{
		ft_printf_fd(2, RED INCORRECT_FILETYPE RESET);
		exit(EXIT_FAILURE);
	}
}
