/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:46:35 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/12/02 23:21:41 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sort(t_head *stack)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (FALSE);
	current = stack->top;
	while (current != stack->bottom && current->next != NULL
		&& current->next->data > current->data)
		current = current->next;
	if (current == stack->bottom)
		return (ft_printf("sorted", TRUE));
	return (FALSE);
}

void	sort_index(t_head *stack, t_node *new_node)
{
	t_node	*top_node;

	if (stack == NULL)
		return ;
	top_node = stack->top;
	while (top_node != NULL)
	{
		if (new_node->data > top_node->data)
			new_node->index++;
		else if (new_node->data < top_node->data)
			top_node->index++;
		top_node = top_node->next;
	}
}

bool	sort_two(t_head *stack)
{
	t_node	*top_node;

	top_node = stack->top;
	if (top_node->data > top_node->next->data)
	{
		swap(stack);
		return (TRUE);
	}
	return (FALSE);
}

int	find_index(t_head *stack, int index)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->index == index)
			return (current->index);
		current = current->next;
	}
	return (-1);
}

int	ft_is_sorted(t_head *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->data > current->next->data)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

t_node	*min_stack(t_head *stack)
{
	t_node	*current;
	t_node	*min;

	current = stack->top;
	min = current;
	while (current)
	{
		if (current->data < min->data)
			min = current;
		current = current->next;
	}
	return (min);
}

t_node	*max_stack(t_head *stack)
{
	t_node	*current;
	t_node	*max;

	current = stack->top;
	max = current;
	while (current)
	{
		if (current->data > max->data)
			max = current;
		current = current->next;
	}
	return (max);
}

bool	sort_three(t_head *stack)
{
	if (stack->top == max_stack(stack) && stack->top->next == min_stack(stack))
		rotate(stack);
	else if (stack->top != min_stack(stack)
		&& stack->top->next == max_stack(stack))
		reverse_rotate(stack);
	else if (stack->top == max_stack(stack)
		&& stack->top->next != min_stack(stack))
	{
		sa(stack);
		reverse_rotate(stack);
	}
	else if (stack->top != min_stack(stack)
		&& stack->top->next == max_stack(stack))
	{
		reverse_rotate(stack);
		sa(stack);
	}
	else if (stack->top != max_stack(stack)
		&& stack->top->next == min_stack(stack))
	{
		sa(stack);
	}
	else if (stack->top == min_stack(stack)
		&& stack->top->next == max_stack(stack))
	{
		sa(stack);
		rotate(stack);
	}
	return (TRUE);
}

bool	search_index(t_head *stack)
{
	t_node	*current;
	int		min_index;
	int		len;
	int		i;

	current = stack->top;
	min_index = current->index;
	i = 0;
	len = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			i++;
		}
		current = current->next;
		len++;
	}
	if (i < (len / 2))
		return (0);
	return (1);
}

int	min_index(t_head *stack)
{
	t_node	*current;
	int		min_index;

	current = stack->top;
	min_index = current->index;
	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}

int	len_stack(t_head *stack)
{
	t_node	*current;
	int		len;

	current = stack->top;
	len = 0;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

bool	sort_five(t_head *stack_a, t_head *stack_b)
{
	while (stack_a->stack_len > 3)
	{
		while (stack_a->top->index != min_index(stack_a))
		{
			if (search_index(stack_a) == 0)
				rotate(stack_a);
			else
				reverse_rotate(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (TRUE);
}

bool	sort(t_head *stack_a, t_head *stack_b)
{
	if (stack_a->stack_len == 2)
		return (sort_two(stack_a));
	else if (stack_a->stack_len == 3)
		return (sort_three(stack_a));
	else if (stack_a->stack_len <= 5)
		return (sort_five(stack_a, stack_b));
	else if (stack_a->stack_len > 5)
		return (sort_above_five(stack_a, stack_b));
	return (FALSE);
}

int	ft_find_largest(t_head *stack)
{
	int		max_index;
	t_node	*current;

	current = stack->top;
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}
int	find_position(t_head *stack)
{
	int		pos;
	int		lenght;
	int		max;
	t_node	*current;

	pos = -1;
	lenght = 0;
	max = stack->top->index;
	current = stack->top->next;
	while (current != NULL)
	{
		if (max < current->index)
		{
			max = current->index;
			pos = lenght;
		}
		current = current->next;
		lenght++;
	}
	if (pos < lenght / 2)
		return (0);
	else
		return (1);
}

int	is_top(t_head *head, t_head *node)
{
	if (head == node)
		return (1);
	return (0);
}

void	sort_stack_b(t_head *stack_a, t_head *stack_b)
{
	int	position;
	int	max_index;

	position = 0;
	max_index = 0;
	while (stack_b->top)
	{
		max_index = ft_find_largest(stack_b);
		position = find_position(stack_b);
		if (position == 0)
		{
			if (max_index == stack_b->top->index && is_top(stack_b,
					stack_b) == 1)
				pa(stack_a, stack_b);
			else
				rotate(stack_b);
		}
		else if (position == 1)
			reverse_rotate(stack_b);
	}
}
bool	sort_above_five(t_head *stack_a, t_head *stack_b)
{
	int i;
	int j;

	i = 0;
	j = 19;
	while (stack_a->top)
	{
		if (stack_a->top->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if (stack_a->top->index <= i + j)
		{
			pb(stack_a, stack_b);
			rotate(stack_b);
			i++;
		}
		else
			rotate(stack_a);
	}
	sort_stack_b(stack_a, stack_b);
	return (TRUE);
}