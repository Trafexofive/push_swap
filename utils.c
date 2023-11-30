
#include "printf/ft_printf.h"
#include "push_swap.h"

// Define a structure for a node in the linked list

// Function to create a new node with the given data
t_node  *create_node(int data)
{
    t_node* new_node;

    new_node = (t_node*)malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev= NULL;
    return new_node;
}


// Function to traverse and print the linked list
void    print_stacks(t_head *stack_a, t_head *stack_b)
//reminder to change for index print support
{
    t_node* current_a = stack_a->top;
    t_node* current_b = stack_b->top;

    ft_printf("\nStack A :\n");
    while (current_b != NULL)
    {
        if (current_b == stack_b->bottom)
            break;
        if (current_b->next)
            ft_printf("%d-> ", current_b->data);
        current_b = current_b->next;
    }
    if (current_b == stack_b->bottom)
        ft_printf("%d | Bottom Reached\n\n", current_b->data);
    ft_printf("Stack B :\n");
    while (current_a != NULL) 
    {
        if (current_a == stack_a->bottom)
            break;
        if (current_a->next && stack_a->bottom != current_a)
            ft_printf("%d -> ", current_a->data);
        current_a = current_a->next;
    }
    if (current_a == stack_a->bottom)
        ft_printf("%d | Bottom Reached\n", current_a->data);
    // ft_printf("NULL\n");
}

// Function to free the memory used by the linked list
void free_stack(t_head* head)
{
    t_node* current = head->top;
    while (current != NULL)
	{
        t_node* temp = current;
        current = current->next;
        free(temp);
    }
}

size_t	ft_strlen_int(int *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int put_intarr(int *tab)
{
    int i;

    i = 0;
    if (!tab)
        return (0);
    while (tab[i++])
    {
        if (!tab[i])
            break;
        ft_printf("Index = %d | %d\n", i, tab[i]);

    }
    return (i);
}

int ft_puttab(char **tab)
{
    int i;

    i = -1;
    if (!tab)
        return (0);
    while (tab[++i])
        ft_printf("Index = %d | %s\n", i, tab[i]);
    return (i);
}

//function to auto_print sizeof;
int *strdup_int(int *arr)
{
    int i;
    int *dupe;

    i = -1;
    if (!arr)
        return (NULL);
    dupe = (int *)malloc(sizeof(arr)); 
    if (!dupe)
        return (NULL);
    while (arr[++i])
        dupe[i] = arr[i];
    return (dupe);
}

bool    is_duped(int *arr)
{
    int i;
    int j;
    int *tmp_str;

    i = 0;
    j = 0;
    tmp_str = strdup_int(arr);
    while (arr[i] && tmp_str)
    {
        while (tmp_str[j])
        {
            if (tmp_str[j] == arr[i])
                return (0);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}
