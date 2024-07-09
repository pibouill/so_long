/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:54:00 by pibouill          #+#    #+#             */
/*   Updated: 2024/03/13 13:29:22 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns the lengths of an array of strings */

#include "libft.h"

int	ft_str_arr_len(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
