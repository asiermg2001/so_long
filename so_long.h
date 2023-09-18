/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:00:33 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/12 10:25:58 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<stddef.h>
# include	<stdlib.h>
# include	<unistd.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"


# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

typedef struct s_mlxstruct
{
	void			*mlx;
	char			*charc;
	void			*empty;
	void			*wall;
	void			*c;
	void			*exit;
	void			*startpos;
	char			*map;
	void			*win;
	int				charx;
	int				chary;
	char			**maparray;
	int				collected;
	int				collectables;
}					t_mlxstruct;

size_t	mapsize(int fd);

char	*checkeol(char **map);

char	*maptostr(int fd, size_t size);

void	freemap(char **map);

void	error_noexit(int i, char **map);

void	error_noini(int i, char **map);

void	errorcollectable(int i, char **map);

int		argerror(int argc);

void	formaterror(char *argv);

void	cantreaderror(char *map);

void	mapcomprobations(char *map);

void	checkminimums(char *map);

void	argvchecks(char *argv);

void	rectangleerror(char **map);

int		maplinelength(char *map);

char	**maptoarray(char *map);

void	findplayerstart(t_mlxstruct *mlx);

void	checkrectangle(char *map);

void	error_invalidchar(char c, char *map);

void	checkinvalidchars(char *map);

void	checkmapclosed(char **maparray, char *map);

void	error_notclosed(char *map, char **maparray);

int		endgame(t_mlxstruct *mlx);

int		mapcolumnlength(char *map);

void	startgame(char *map);

void	initializemlx(char *map, t_mlxstruct *m, int *imgwidth, int *imgheight);

void	writemap(t_mlxstruct *mlx);

void	move(t_mlxstruct *mlx, int i, int j);

void	moveup(t_mlxstruct *mlx);

void	movedown(t_mlxstruct *mlx);

void	moveleft(t_mlxstruct *mlx);

void	moveright(t_mlxstruct *mlx);

void	findpath(char *map);

void	error_invalidpath(char **map, char **maparray);

#endif