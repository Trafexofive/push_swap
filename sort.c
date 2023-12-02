
#include "push_swap.h"

bool is_sort(t_head *stack)
{
	t_node *current;

	if (stack == NULL || stack->top == NULL)
		return FALSE;

	current = stack->top;
	while (current != stack->bottom && current->next != NULL && current->next->data > current->data)
		current = current->next;
	if (current == stack->bottom)
		return (ft_printf("sorted", TRUE));
	return FALSE;
    //not working to fix
}



void    sort_index(t_head *stack, t_node *new_node)
{
    t_node  *top_node;

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

// hardcoded cases


bool    sort_two(t_head *stack)
{
    t_node  *top_node;

    top_node = stack->top;
    if (top_node->data > top_node->next->data)
    {
        swap(stack);
        return (TRUE);
    }
     return FALSE;
}


// bool sort_three(t_head *stack)
// {
// 	t_node *top_node;
// 	t_node *next_node;
// 	t_node *prev_node;

// 	top_node = stack->top;
// 	next_node = top_node->next;
// 	prev_node = top_node->prev;

// 	if (top_node->data > next_node->data && next_node->data < prev_node->data)
// 	{
// 		rotate(stack);
// 		return TRUE;
// 	}
// 	else if (top_node->data > next_node->data && next_node->data > prev_node->data)
// 	{
// 		reverse_rotate(stack);
// 		return TRUE;
// 	}
// 	else if (top_node->data < next_node->data && next_node->data > prev_node->data)
// 	{
// 		swap(stack);
// 		return TRUE;
// 	}
// 	else if (top_node->data > next_node->data && next_node->data > prev_node->data)
// 	{
// 		swap(stack);
// 		rotate(stack);
// 		return TRUE;
// 	}
// 	else if (top_node->data < next_node->data && next_node->data < prev_node->data)
// 	{
// 		reverse_rotate(stack);
// 		swap(stack);
// 		return TRUE;
// 	}

// 	return FALSE;
// }

//int find_position

bool    sort_three(t_head *stack)
{

		ft_putstr_fd("stop", 1);
	if (stack->top->index == 0 && stack->top->next->index == 1 && stack->top->next->next->index == 2)
		return (TRUE);
	else if (stack->top->index == 0 && stack->top->next->index == 2 && stack->top->next->next->index == 1)
	{
		swap(stack);
		rotate(stack);
		return (TRUE);
	}
	else if (stack->top->index == 1 && stack->top->next->index == 0 && stack->top->next->next->index == 2)
	{
		reverse_rotate(stack);
		return (TRUE);
	}
	else if (stack->top->index == 1 && stack->top->next->index == 2 && stack->top->next->next->index == 0)
	{
		rotate(stack);
		return (TRUE);
	}
	else if (stack->top->index == 2 && stack->top->next->index == 0 && stack->top->next->next->index == 1)
	{
		swap(stack);
		reverse_rotate(stack);
		return (TRUE);
	}
	else if (stack->top->index == 2 && stack->top->next->index == 1 && stack->top->next->next->index == 0)
	{
		rotate(stack);
		swap(stack);
		return (TRUE);
	}
    return (FALSE);
}

bool    sort(t_head *stack_a, t_head *stack_b)
{
    if (stack_a->stack_len == 2) 
        return (sort_two(stack_a));
    else if (stack_a->stack_len == 3)
        return (sort_three(stack_a));
	else if (stack_a->stack_len > 5)
		return (sort_above_five(stack_a, stack_b));

    return (FALSE);
}



bool sort_above_five(t_head *stack_a, t_head *stack_b)
{
	int i;
	int j;

	i = 0;
	j = 19;

	while (stack_a)
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


		stack_a->top = stack_a->top->next;
	}
	return (TRUE);
}