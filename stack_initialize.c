/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:13:03 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/12/02 23:13:06 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_2(t_head *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack->top;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(stack);
}

t_node	*create_node(int data, int index)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->index = index;
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	fill_node(int data, t_head **stack)
{
	t_node	*new_node;

	new_node = create_node(data, 0);
	if (!new_node)
		return ;
	if ((*stack)->top == NULL)
	{
		(*stack)->top = new_node;
		(*stack)->current = new_node;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = (*stack)->current;
		(*stack)->current->next = new_node;
		(*stack)->current = new_node;
		(*stack)->bottom = new_node;
		sort_index(*stack, new_node);
	}
}
void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

bool	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (i == 1 && str[i] == '\0')
		return (TRUE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

bool	check_number(char *str)
{
	long	num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN || ft_strlen(str) > 11
		|| check_digit(str))
		return (false);
	return (true);
}

t_node	*create_stack(int len, char **arr, t_head *stack)
{
	int	i;

	i = 0;
	while (arr && i < len)
	{
		fill_node(atol(arr[i]), &stack);
		stack->stack_len++;
		i++;
	}
	return (stack->bottom);
}

t_head	*stack_init(char c)
{
	t_head	*new_stack;

	new_stack = (t_head *)ft_calloc(1, sizeof(t_head));
	if (new_stack == NULL)
		return (NULL);
	new_stack->name = c;
	new_stack->stack_len = 0;
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	return (new_stack);
}
