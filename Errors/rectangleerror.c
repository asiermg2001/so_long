/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangleerror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:25:03 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/18 08:48:51 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rectangleerror(char **map)
{
	ft_printf("Error\nEl mapa no es rectangular");
	map = NULL;
	exit(-1);
}
