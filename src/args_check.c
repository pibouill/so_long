/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:10:54 by pibouill          #+#    #+#             */
/*   Updated: 2024/06/26 14:40:47 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define INCORRECT_FILETYPE "Incorrect filetype.\nUse <mapname>.ber only.\n"

bool	is_ber_file(char *filename)
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
	ft_printf_fd(2, RED INCORRECT_FILETYPE RESET);
	return (false);
}
