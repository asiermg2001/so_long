/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:43:37 by amarcos-          #+#    #+#             */
/*   Updated: 2023/07/17 10:39:23 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkminimums(char *map)
{
	int		startn;
	int		exitn;
	int		collectn;
	int		i;

	i = 0;
	startn = 0;
	exitn = 0;
	collectn = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			exitn++;
		if (map[i] == 'C')
			collectn++;
		if (map[i] == 'P')
			startn++;
		i++;
	}
	if (exitn != 1)
		error_noexit(exitn, &map);
	if (collectn < 1)
		errorcollectable(collectn, &map);
	if (startn != 1)
		error_noini(startn, &map);
}

int	maplinelength(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n' && map[i])
		i++;
	return (i);
}

int	mapcolumnlength(char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int	isrectangular(char *map)
{
	int	linewidth;

	linewidth = maplinelength(map);
	map = linewidth + map + 1;
	while (*map)
	{
		if (maplinelength(map) != linewidth)
			return (0);
		map = linewidth + map + 1;
	}
	return (1);
}

void	checkrectangle(char *map)
{
	if (!isrectangular(map))
		rectangleerror(&map);
}

