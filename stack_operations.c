
#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_node	*last_node(t_head *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp->next && tmp->next != stack->top)
		tmp = tmp->next;
	return (tmp);
}

void	swap(t_head *stack)
{
	t_node	*tmp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	tmp = stack->top;
	ft_swap(&tmp->data, &tmp->next->data);
	ft_swap(&tmp->index, &tmp->next->index);
}

void	sa(t_head *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_head *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	pa(t_head *stack_a, t_head *stack_b)
{
	t_node	*tmp;

	if (stack_b->top == NULL)
		return ;
	if (stack_a->top == NULL)
	{
		stack_a->top = stack_b->top;
		stack_b->top = stack_b->top->next;
		stack_a->top->next = NULL;
	}
	else
	{
		tmp = stack_b->top;
		stack_b->top = stack_b->top->next;
		tmp->next = stack_a->top;
		stack_a->top = tmp;
	}
	stack_a->stack_len++;
	stack_b->stack_len--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_head *stack_a, t_head *stack_b)
{
	t_node	*tmp;

	if (stack_a->top == NULL)
		return ;
	if (stack_b->top == NULL)
	{
		stack_b->top = stack_a->top;
		stack_a->top = stack_a->top->next;
		stack_b->top->next = NULL;
	}
	else
	{
		tmp = stack_a->top;
		stack_a->top = stack_a->top->next;
		tmp->next = stack_b->top;
		stack_b->top = tmp;
	}
	stack_b->stack_len++;
	stack_a->stack_len--;
	ft_putstr_fd("pb\n", 1);
}

void	rotate(t_head *stack)
{
	t_node	*first;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	first = stack->top;
	last_node(stack)->next = first;
	stack->top = stack->top->next;
	first->next = NULL;
	if (stack->name == 'a')
		ft_printf("ra\n");
	if (stack->name == 'b')
		ft_printf("rb\n");
}

void	rr(t_head *stack_a, t_head *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_head *stack)
{
	t_node	*last;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	last = last_node(stack);
	last->next = stack->top;
	stack->top = last;
	last_node(stack)->next = NULL;
	if (stack->name == 'a')
		ft_printf("rra\n");
	else if (stack->name == 'b')
		ft_printf("rrb\n");
}

void	rrr(t_head *stack_a, t_head *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
