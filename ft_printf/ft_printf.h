/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcos- <amarcos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:19:09 by amarcos-          #+#    #+#             */
/*   Updated: 2023/06/13 10:14:08 by amarcos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *s, ...);

int		ft_printchar(int c);

int		ft_printstr(char *str);

int		ft_checkformat(va_list args, const char format);

int		ft_printptr(unsigned long long ptr);

void	ft_ptrtohex(uintptr_t num);

int		ft_ptrlen(uintptr_t num);

int		ft_printunsigned(unsigned int num);

char	*ft_unsigneditoa(unsigned int num);

int		ft_printnumber(int num);

int		ft_numlen(unsigned int num);

int		ft_hexlen(unsigned int num);

void	ft_puthex(unsigned int num, const char format);

int		ft_printhex(unsigned int num, const char format);

char	*ft_itoa(int n);

void	ft_putchar_fd(char c, int fd);

char	*ft_inttoarray(char *str, unsigned int number, long int numlen);

int		ft_itoanumlen(long int n);

#endif