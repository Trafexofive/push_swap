
#include "printf/ft_printf.h"
#include "push_swap.h"

// Define a structure for a node in the linked list


// Function to traverse and print the linked list
void    print_stacks(t_head *stack_a, t_head *stack_b)
//reminder to change for index print support
{
    t_node* current_a = stack_a->top;
    t_node* current_b = stack_b->top;

	if (stack_b->top == NULL)
	{
		ft_printf("Stack B is empty\n");
		    ft_printf("Stack A :\n");
    	while (current_a != NULL) 
    	{
            	ft_printf("%d | %d\n", current_a->index, current_a->data);
    	    current_a = current_a->next;

    	}

		return ;
	}
		ft_printf("Stack A :\n");
    	while (current_a != NULL) 
    	{
            ft_printf("%d | %d\n", current_a->index, current_a->data);
    	    current_a = current_a->next;
    	}
        	
	
    ft_printf("\nStack B :\n");
    while (current_b != NULL)
    {
        ft_printf("%d | %d\n", current_b->index, current_b->data);
        current_b = current_b->next;
    }
    // if (current_b != NULL)
	// {
    //     ft_printf("%d | %d \n---------\n", current_b->index, current_b->data);
	// }
}

void matrix_free(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

// Function to free the memory used by the linked list
void free_stack(t_head* stack)
{
    t_node* current = stack->top;
    while (current != NULL)
	{
        t_node* temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
    stack->bottom = NULL;
}

size_t	ft_strlen_int(int *c)
{
	size_t	i;

	i = 0;
	while (c[i] && c)
		i++;
	return (i);
}

int put_intarr(int *tab)
{
    int i;

    i = -1;
    if (!tab)
        return (0);
    while (tab[++i])
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
                return (TRUE);
            j++;
        }
        j = 0;
        i++;
    }
    return (FALSE);
}
