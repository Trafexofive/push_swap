
#include "printf/ft_printf.h"
#include "push_swap.h"
#include <stdbool.h>

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

void    push(t_head *stack_a, t_head *stack_b, char option)
{
    //split it up.
    t_node  *node;
    t_node  *top_a;
    t_node  *top_b;

    node = create_node(stack_a->top->data);
    top_a= stack_a->top;
    top_b= stack_b->top;
    if (!node)
        return ;
    if (option == 'a')
    {
        top_b->prev = node;
        node->next = top_b;
        node->prev = NULL;
        stack_b->top = node;
        top_a->prev = NULL;
        free(stack_a->top);
        stack_a->top = top_a->next;
    }
    else
    {
        top_a->prev = node;
        node->next = top_a;
        node->prev = NULL;
        stack_a->top = node;
        top_b->prev = NULL;
        free(stack_b->top);
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
		return TRUE;
	return FALSE;
}


//function to index sorted elements

// void    sort_index(t_head *stack)
// {
//     t_node  *current;
//
//     current = stack->top;
//     
// }

// hardcoded cases


void    sort_two(t_head *stack)
{

    t_node  *top_node;

    top_node = stack->top;
    if (top_node->data < top_node->next->data)
        swap(stack);
}

void    sort_three(t_head *stack)
{
    t_node  *top_node;

    top_node = stack->top;
    
}

void    sort(t_head *stack)
{
    if (stack->stack_len == 2)
        sort_two(stack);
}
