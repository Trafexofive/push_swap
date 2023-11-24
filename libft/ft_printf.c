/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:56:57 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/06/07 01:46:59 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_specifier(va_list list, int c, int *count)
{
	if (c == '\n')
		ft_putchar(c, count);
	if (c == '%')
		ft_putchar('%', count);
	else if (c == 'c')
		ft_putchar(va_arg(list, int), count);
	else if (c == 's')
		ft_putstr(va_arg(list, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(list, int), count);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(list, unsigned int), count);
	else if (c == 'x')
		ft_puthexa(va_arg(list, unsigned int), count);
	else if (c == 'X')
		ft_puthexa_caps(va_arg(list, unsigned int), count);
	else if (c == 'p')
	{
		ft_putstr("0x", count);
		ft_puthexa(va_arg(list, unsigned long), count);
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	count = 0;
	va_start(list, format);
	while (format[i])
	{
		if (write(1, 0, 0) == -1)
			return (-1);
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			ft_specifier(list, format[i], &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	return (count);
}
