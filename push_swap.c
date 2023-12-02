/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:48:52 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/12/02 23:17:41 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>

// void leak()
// {
// 	system("leaks push_swap");
// }
	// atexit(leak);

int	main(int ac, char **av)
{
	t_head	*stack_a;
	t_head	*stack_b;

	stack_a = ft_parse(ac, av);
	if (stack_a == NULL)
		exit (EXIT_SUCCESS);
	stack_b = stack_init('b');
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	exit (EXIT_SUCCESS);
}
