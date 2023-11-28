/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:53:39 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/06/06 22:19:31 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned long n, int *count)
{
	const char	*base_x;

	base_x = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthexa(n / 16, count);
		ft_puthexa(n % 16, count);
	}
	if (n <= 15)
		ft_putchar(base_x[n % 16], count);
}
