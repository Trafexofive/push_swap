/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:08:41 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/06/05 20:30:03 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, count);
		ft_putchar(n % 10 + 48, count);
	}
	else
		ft_putchar(n % 10 + 48, count);
}
