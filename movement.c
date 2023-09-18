/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:44:41 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/04 09:20:47 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_mlxstruct *mlx, int i, int j)
{
	static size_t	movecount = 0;

	if (mlx->maparray[i][j] == '0' || mlx->maparray[i][j] == 'C')
	{
		mlx->maparray[mlx->chary][mlx->charx] = '0';
		if (mlx->maparray[i][j] == 'C')
			mlx->collected++;
		mlx->maparray[i][j] = 'P';
		movecount++;
		ft_printf("Numero de movimientos: %u\n", movecount);
	}
	if (mlx->maparray[i][j] == 'E')
		if (mlx->collected == mlx->collectables)
			endgame(mlx);
}

void	moveup(t_mlxstruct *mlx)
{
	move(mlx, mlx->chary - 1, mlx->charx);
}

void	movedown(t_mlxstruct *mlx)
{
	move(mlx, mlx->chary + 1, mlx->charx);
}

void	moveleft(t_mlxstruct *mlx)
{
	move(mlx, mlx->chary, mlx->charx - 1);
}

void	moveright(t_mlxstruct *mlx)
{
	move(mlx, mlx->chary, mlx->charx + 1);
}
