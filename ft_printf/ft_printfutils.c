/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:02:43 by amarcos-          #+#    #+#             */
/*   Updated: 2023/06/13 10:36:09 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_inttoarray(char *str, unsigned int number, long int numlen)
{
	while (number > 0)
	{
		str[numlen--] = (number % 10) + 48;
		number = number / 10;
	}
	return (str);
}

int	ft_itoanumlen(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			numlen;
	long int	number;

	number = n;
	numlen = ft_itoanumlen(n);
	str = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!str)
		return (0);
	str[numlen--] = '\0';
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	str = ft_inttoarray(str, number, numlen);
	return (str);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
