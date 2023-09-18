/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:10:59 by amarcos-          #+#    #+#             */
/*   Updated: 2023/06/13 10:02:16 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkformat(va_list args, const char format)
{
	int	printlen;

	printlen = 0;
	if (format == 'c')
		printlen += ft_printchar(va_arg(args, int));
	else if (format == 's')
		printlen += ft_printstr(va_arg(args, char *));
	else if (format == '%')
		printlen += write (1, "%", 1);
	else if (format == 'p')
		printlen += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		printlen += ft_printnumber(va_arg(args, int));
	else if (format == 'u')
		printlen += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'X' || format == 'x')
		printlen += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		printlen += write(1, "%", 1);
	return (printlen);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		printlen;

	i = 0;
	printlen = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			printlen += ft_checkformat(args, s[i + 1]);
			i++;
		}
		else
			printlen += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (printlen);
}
