/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappathinvalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:29:28 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/18 08:41:24 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_invalidpath(char **map, char **maparray)
{
	ft_printf("Error\nEL mapa no tiene path posible\n");
	map = NULL;
	maparray = NULL;
	exit(-1);
}
