/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimumserror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:00:51 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/18 08:46:21 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_noexit(int i, char **map)
{
	ft_printf("Error\nDebería de haber 1 salida y hay: %i\n", i);
	map = NULL;
	exit(-1);
}

void	error_noini(int i, char **map)
{
	ft_printf("Error\nDebería de haber 1 inicio y hay: %i\n", i);
	map = NULL;
	exit(-1);
}

void	errorcollectable(int i, char **map)
{
	ft_printf("Error\nDebería haber al menos 1 collectable y hay: %i\n", i);
	map = NULL;
	exit(-1);
}
