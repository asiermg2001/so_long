/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:08:15 by amarcos-          #+#    #+#             */
/*   Updated: 2023/07/17 11:02:32 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	mapsize(int fd)
{
	char	c;
	ssize_t	r;
	size_t	i;

	i = 0;
	c = 0;
	r = read(fd, &c, 1);
	while (r == 1 && c)
	{
		r = read(fd, &c, 1);
		i++;
	}
	close(fd);
	return (i);
}

char	*checkeol(char **map)
{
	char	*eol;
	char	*aux;

	if (map[0][ft_strlen(*map) - 1] == '\n')
		return (*map);
	eol = ft_strdup("\n");
	aux = *map;
	if (!eol || !aux)
		exit(-5);
	*map = ft_strjoin(aux, eol);
	free(aux);
	free(eol);
	return (*map);
}

char	*maptostr(int fd, size_t size)
{
	char	c;
	ssize_t	r;
	char	*map;
	size_t	i;

	map = ft_calloc(sizeof(char), size + 1);
	if (!map)
		exit(-2);
	i = 0;
	r = read(fd, &c, 1);
	while (r == 1 && c)
	{
		map[i] = c;
		r = read(fd, &c, 1);
		i++;
	}
	close(fd);
	map[i] = 0;
	map = checkeol(&map);
	return (map);
}
