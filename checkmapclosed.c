/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmapclosed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:50:40 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/12 10:26:05 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkfirstlastlines(char **maparray, int numberoflines)
{
	int	i;

	i = 0;
	while (maparray[0][i])
	{
		if (maparray[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (maparray[numberoflines - 1][i])
	{
		if (maparray[numberoflines - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	checkmiddlelines(char **maparray, int numberoflines, int linelength)
{
	int	j;

	j = 1;
	while (j < numberoflines - 1)
	{
		if (maparray[j][0] != '1' || maparray[j][linelength - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

void	checkmapclosed(char **maparray, char *map)
{
	int	linelength;
	int	numberoflines;
	int	i;

	i = 0;
	numberoflines = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			numberoflines++;
		i++;
	}
	linelength = (i - numberoflines) / numberoflines;
	if (!checkfirstlastlines(maparray, numberoflines) || \
	!checkmiddlelines(maparray, numberoflines, linelength))
		error_notclosed(map, maparray);
}
