/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:02:10 by amarcos-          #+#    #+#             */
/*   Updated: 2023/06/13 10:02:33 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

int	ft_printnumber(int num)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(num);
	i = ft_printstr(str);
	free(str);
	return (i);
}

char	*ft_unsigneditoa(unsigned int num)
{
	char	*str;
	int		i;

	i = ft_numlen(num);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = '\0';
	while (num != 0)
	{
		str[i - 1] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	return (str);
}

int	ft_printunsigned(unsigned int num)
{
	int		printlen;
	char	*str;

	printlen = 0;
	if (num == 0)
		printlen += write(1, "0", 1);
	else
	{
		str = ft_unsigneditoa(num);
		printlen += ft_printstr(str);
		free(str);
	}
	return (printlen);
}
