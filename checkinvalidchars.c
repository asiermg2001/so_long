/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinvalidchars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:13:50 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/12 10:24:39 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkvalidchar(char map)
{
	if (map == '0' || map == '1' || map == 'C' || map == 'E' || map == 'P' || \
		map == '\n')
	{
		return (1);
	}
	return (0);
}

void	checkinvalidchars(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!checkvalidchar(map[i]))
			error_invalidchar(map[i], map);
		i++;
	}
}
