/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:09:22 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/18 08:35:27 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemlx(void *pointer)
{
	if (pointer)
	{
		free(pointer);
		pointer = 0;
	}
}

int	endgame(t_mlxstruct *mlx)
{
	freemlx(mlx->map);
	freemap(mlx->maparray);
	//system("leaks so_long");
	exit(0);
	return (0);
}
