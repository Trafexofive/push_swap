/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:51:35 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/06/06 19:25:25 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putchar(int c, int *count);
void	ft_putstr(const char *s, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbr_unsigned(unsigned int n, int *count);
void	ft_puthexa(unsigned long n, int *count);
void	ft_puthexa_caps(unsigned long n, int *count);
int		ft_printf(const char *format, ...);

#endif
