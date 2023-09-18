/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcomprobations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:55:14 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/12 09:37:27 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	findplayerstart(t_mlxstruct *mlx)
{
	int			i;
	int			j;

	i = 0;
	while (mlx->maparray[i] != NULL)
	{
		j = 0;
		while (mlx->maparray[i][j] != '\0')
		{
			if (mlx->maparray[i][j] == 'C')
				mlx->collectables = mlx->collectables + 1;
			if (mlx->maparray[i][j] == 'P')
			{
				mlx->charx = j;
				mlx->chary = i;
			}
			j++;
		}
		i++;
	}
}

void	mapcomprobations(char *map)
{
	char	**maparray;

	maparray = maptoarray(map);
	checkminimums(map);
	checkrectangle(map);
	checkinvalidchars(map);
	checkmapclosed(maparray, map);
	findpath(map);
	startgame(map);
}
