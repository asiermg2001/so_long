/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalidcharserror.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:38:01 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/18 08:40:07 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_invalidchar(char c, char *map)
{
	ft_printf("Se ha encontrado un caracter invalido :%c", c);
	free(map);
	exit(-1);
}
