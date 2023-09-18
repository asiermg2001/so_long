/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:09:18 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/11 09:43:26 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	canread(char *map)
{
	int		fd;
	char	buf[10];

	fd = open(map, O_RDONLY);
	if (fd < 3)
	{
		close (fd);
		return (0);
	}
	if (read(fd, buf, O_RDONLY))
	{
		close (fd);
		return (0);
	}
	close (fd);
	return (1);
}

void	startmap(char *map)
{
	int	fd1;
	int	fd2;

	if (!canread(map))
		cantreaderror(map);
	fd1 = open(map, O_RDONLY);
	fd2 = open(map, O_RDONLY);
	mapcomprobations(maptostr(fd2, mapsize(fd1)));
}

int	checkformat(char *argv)
{
	if (argv)
	{
		if (ft_strlen(argv) < 4)
			return (0);
		if (!ft_strncmp(argv + (ft_strlen(argv) - 4), ".ber", 4))
			return (1);
	}
	return (0);
}

void	argvchecks(char *argv)
{
	if (!checkformat(argv))
		formaterror(argv);
	startmap(argv);
}
