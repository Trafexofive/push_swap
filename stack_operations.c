
#include "push_swap.h"

void    pop_last(t_head *stack)
{
    t_node  *last_node;

    last_node = stack->bottom;
    stack->bottom = last_node->prev;
    last_node->prev->next = NULL;
    free(last_node);
}

void    pop(t_head *stack, unsigned int index)
{
    
    // top and bottom pop behavior unsure.
    // unsafe to use. recode
    t_node* current;
    t_node  *tmp;

    current = stack->top;
    while (current != NULL && index > 0)
	{   
        current = current->next;
        index--;
    }
    tmp = current->prev;
    // logical problem
    current->prev = current->next->prev;
    current->next = tmp->next;
    free(current);
}

void    swap(t_head *stack)
{
    t_node  *top_next_node;
    t_node  *top_node;


    top_node = stack->top;
    top_next_node = stack->top->next;
    // The stack is empty or has only one element, nothing to swap
	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return;

    top_node->next = top_next_node->next;
    top_node->prev = top_next_node;
    top_next_node->prev = NULL;
    top_next_node->next = top_node;
    stack->top = top_next_node;
    if (stack->stack_len == 2)
        stack->bottom = top_node;

}

// if (stack_bottom->next) check if that is true and handle
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

void    push(t_head *stack_a, t_head *stack_b, char option)
{
	t_node  *top_a;
	t_node  *top_b;

	top_a = stack_a->top;
	top_b = stack_b->top;

	if (option == 'a')
	{
		if (top_a == NULL)
			return;
		
		top_a->prev = top_b;
		top_b->next = top_a;
		top_b->prev = NULL;
		stack_b->top = top_b;
		stack_a->top = top_a->next;
	}
	else
	{
		if (top_b == NULL)
			return;
		
		top_b->prev = top_a;
		top_a->next = top_b;
		top_a->prev = NULL;
		stack_a->top = top_a;
		stack_b->top = top_b->next;
    }
}
	
void    rotate(t_head *stack)
{
    //protect
    t_node  *top_node;
    t_node  *bottom_node;
    t_node  *top_next_node;

    top_node = stack->top;
    bottom_node = stack->bottom;
    top_next_node = stack->top->next;

    bottom_node->next = top_node;
    top_node->prev = bottom_node;
    top_node->next = NULL;
    top_next_node->prev = NULL;
    stack->top = top_next_node;
    stack->bottom = top_node;
    if (stack->name == 'a')
        ft_printf("ra\n");
    if (stack->name == 'b')
        ft_printf("rb\n");
}

void    rr(t_head *stack_a, t_head *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}

void    reverse_rotate(t_head *stack)
{
    //The last element becomes the first one.

    t_node  *top_node;
    t_node  *bottom_node;
    t_node  *bottom_prev_node;

    top_node = stack->top;
    bottom_node = stack->bottom;
    bottom_prev_node = bottom_node->prev;

    bottom_node->prev = NULL;
    bottom_node->next = top_node;
    bottom_prev_node->next = NULL;
    stack->bottom = bottom_prev_node;
    stack->top = bottom_node;
    
    if (stack->name == 'a')
        ft_printf("rra\n");
    if (stack->name == 'b')
        ft_printf("rrb\n");
}

void    rrr(t_head *stack_a, t_head *stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}

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
