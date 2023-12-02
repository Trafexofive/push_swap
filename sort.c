
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


//function to index sorted elements

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
        else
            break ;
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


bool sort_three(t_head *stack)
{
	t_node *top_node;
	t_node *next_node;
	t_node *prev_node;

	top_node = stack->top;
	next_node = top_node->next;
	prev_node = top_node->prev;

	if (top_node->data > next_node->data && next_node->data < prev_node->data)
	{
		rotate(stack);
		return TRUE;
	}
	else if (top_node->data > next_node->data && next_node->data > prev_node->data)
	{
		reverse_rotate(stack);
		return TRUE;
	}
	else if (top_node->data < next_node->data && next_node->data > prev_node->data)
	{
		swap(stack);
		return TRUE;
	}
	else if (top_node->data > next_node->data && next_node->data > prev_node->data)
	{
		swap(stack);
		rotate(stack);
		return TRUE;
	}
	else if (top_node->data < next_node->data && next_node->data < prev_node->data)
	{
		reverse_rotate(stack);
		swap(stack);
		return TRUE;
	}

	return FALSE;
}

// bool    sort_three(t_head *stack)
// {
//     t_node  *top_node;
//
//     top_node = stack->top;
//     
// }

bool    sort(t_head *stack)
{
    if (stack->stack_len == 2)      
        return (sort_two(stack));
    else if (stack->stack_len == 3)
        return (sort_three(stack));

    return (FALSE);
}
