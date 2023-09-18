/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:06:30 by amarcos-          #+#    #+#             */
/*   Updated: 2023/06/13 10:02:37 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(uintptr_t num)
{
	int	ptrlen;

	ptrlen = 0;
	while (num != 0)
	{
		ptrlen++;
		num = num / 16;
	}
	return (ptrlen);
}

void	ft_ptrtohex(uintptr_t num)
{
	if (num >= 16)
	{
		ft_ptrtohex(num / 16);
		ft_ptrtohex(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	printlen;

	printlen = 0;
	printlen += write(1, "0x", 2);
	if (!ptr)
		printlen += write(1, "0", 1);
	else
	{
		ft_ptrtohex(ptr);
		printlen += ft_ptrlen(ptr);
	}
	return (printlen);
}
