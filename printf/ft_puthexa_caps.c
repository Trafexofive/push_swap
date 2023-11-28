/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_caps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:12:48 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/06/06 22:19:17 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_caps(unsigned long n, int *count)
{
	const char	*base_caps;

	base_caps = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_puthexa_caps(n / 16, count);
		ft_puthexa_caps(n % 16, count);
	}
	if (n <= 15)
		ft_putchar(base_caps[n % 16], count);
}
