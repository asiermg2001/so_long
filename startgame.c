/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:28:59 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/12 09:37:09 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checknullmlx(void *pointer, t_mlxstruct *mlx)
{
	if (!pointer)
	{
		ft_printf("Error");
		endgame(mlx);
	}
}

void	initializemlx(char *map, t_mlxstruct *m, int *imgwidth, int *imgheight)
{
	m->mlx = 0;
	m->c = 0;
	m->charc = 0;
	m->empty = 0;
	m->exit = 0;
	m->startpos = 0;
	m->wall = 0;
	m->map = map;
	m->collectables = 0;
	m->collected = 0;
	m->mlx = mlx_init();
	checknullmlx(m->mlx, m);
	m->win = mlx_new_window(m->mlx, maplinelength(map) * 32, \
	mapcolumnlength(map) * 32, "so_long");
	checknullmlx(m->win, m);
	m->c = mlx_xpm_file_to_image(m->mlx, "img/c.xpm", imgwidth, imgheight);
	checknullmlx(m->c, m);
	m->charc = mlx_xpm_file_to_image(m->mlx, "img/ch.xpm", imgwidth, imgheight);
	checknullmlx(m->charc, m);
	m->empty = mlx_xpm_file_to_image(m->mlx, "img/f.xpm", imgwidth, imgheight);
	checknullmlx(m->empty, m);
	m->exit = mlx_xpm_file_to_image(m->mlx, "img/e.xpm", imgwidth, imgheight);
	checknullmlx(m->exit, m);
	m->wall = mlx_xpm_file_to_image(m->mlx, "img/w.xpm", imgwidth, imgheight);
	checknullmlx(m->wall, m);
}

int	keyhook(int i, t_mlxstruct *mlx)
{
	if (i == ESC)
		endgame(mlx);
	if (i == W || i == UP)
		moveup(mlx);
	if (i == S || i == DOWN)
		movedown(mlx);
	if (i == A || i == LEFT)
		moveleft(mlx);
	if (i == D || i == RIGHT)
		moveright(mlx);
	writemap(mlx);
	return (0);
}

void	startgame(char *map)
{
	t_mlxstruct	mlx;
	int			*imgwidth;
	int			*imgheight;
	int			value;

	value = 32;
	imgwidth = &value;
	imgheight = &value;
	initializemlx(map, &mlx, imgwidth, imgheight);
	mlx.maparray = ft_split(map, '\n');
	checknullmlx(mlx.maparray, &mlx);
	findplayerstart(&mlx);
	writemap(&mlx);
	mlx_key_hook(mlx.win, keyhook, &mlx);
	mlx_hook(mlx.win, 17, 0, endgame, &mlx);
	mlx_loop(mlx.mlx);
}
