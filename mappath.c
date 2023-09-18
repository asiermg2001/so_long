/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:58:32 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/12 10:21:42 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	**maptoarray(char *map)
{
	char	**maparray;

	maparray = ft_split(map, '\n');
	return (maparray);
}

void	check(char **map, int x, int y)
{
	map[y][x] = 'R';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'R')
		check(map, x, y + 1);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'R')
		check(map, x, y - 1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'R')
		check(map, x + 1, y);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'R')
		check(map, x - 1, y);
}

int	patherrorcheck(char **mapcopy)
{
	int	a;
	int	b;

	a = 0;
	while (mapcopy[a])
	{
		b = 0;
		while (mapcopy[a][b])
		{
			if (mapcopy[a][b] != 'R' && mapcopy[a][b] != '1')
			{
				freemap(mapcopy);
				return (1);
			}
			b++;
		}
	a++;
	}
	freemap(mapcopy);
	return (0);
}

void	findpath(char *map)
{
	char	**mapcopy;
	int		a;
	int		b;
	int		i;
	int		j;

	a = 0;
	mapcopy = maptoarray(map);
	while (mapcopy[a])
	{
		b = 0;
		while (mapcopy[a][b] != '\0')
		{
			if (mapcopy[a][b] == 'P')
			{
				i = a;
				j = b;
			}
			b++;
		}
	a++;
	}
	check(mapcopy, j, i);
	if (patherrorcheck(mapcopy))
		error_invalidpath(mapcopy, &map);
}
