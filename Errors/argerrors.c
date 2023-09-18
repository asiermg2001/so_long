/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argerrors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:48:54 by amarcos-          #+#    #+#             */
/*   Updated: 2023/09/18 08:39:38 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	argerror(int argc)
{
	ft_printf("Error\n");
	ft_printf("Has introducido %i argumentos", argc - 1);
	ft_printf("y deberia de haber solo uno\n");
	return (-1);
}

void	formaterror(char *argv)
{
	ft_printf("Error\nEl formato %s no es el esperado .ber\n", argv);
	exit (-1);
}

void	cantreaderror(char *map)
{
	ft_printf("Error\nNo se ha podido leer el archivo %s\n", map);
	exit (-1);
}
