/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapnotclosederror.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:46:07 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/18 08:40:35 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_notclosed(char *map, char **maparray)
{
	ft_printf("Error\nEL mapa no esta cerrado\n");
	free(map);
	freemap(maparray);
	exit (-1);
}
