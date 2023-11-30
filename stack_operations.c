
#include "printf/ft_printf.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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
    t_node* current = stack->top;
    t_node  *tmp;
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
    t_node  *next;
    t_node  *top;

    // The stack is empty or has only one element, nothing to swap
	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
    {
        return;
    }
    top = stack->top;
    next = top->next;

    top->next = next->next;
    next->next = top;
    top->prev = next;
    next->prev = NULL;
	top = next;
	top->next->prev = top;

}

void	sa(t_head *stack_a)
{
	swap(stack_a);
}

void	sb(t_head *stack_b)
{
	swap(stack_b);
}

void    push(t_head *stack_a, t_head *stack_b, char option)
{
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
    //The first element becomes the last one
    //protect
    
    t_node  *top_node;
    t_node  *bottom_node;
    t_node  *top_next_node;

    top_node = stack->top;
    bottom_node = stack->bottom;
    top_next_node = stack->top->next;

    bottom_node->next = stack->top;
    //swaping
    
    top_node->prev = bottom_node;
    top_node->next = NULL;

    top_next_node->prev = NULL;
    stack->top = top_next_node;
    stack->bottom = top_node;
    //update
    
}

//reverse rotate;




