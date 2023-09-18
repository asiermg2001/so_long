/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:00:55 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/12 09:30:09 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	writeimages(char c, int x, int y, t_mlxstruct *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->empty, x * 32, y * 32);
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, x * 32, y * 32);
	if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, x * 32, y * 32);
	if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c, x * 32, y * 32);
	if (c == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->charc, x * 32, y * 32);
}

void	writemap(t_mlxstruct *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->maparray[i] != NULL)
	{
		j = 0;
		while (mlx->maparray[i][j] != '\0')
		{
			if (mlx->maparray[i][j] == 'P')
			{
				mlx->charx = j;
				mlx->chary = i;
			}
			writeimages(mlx->maparray[i][j], j, i, mlx);
			j++;
		}
		i++;
	}
}
