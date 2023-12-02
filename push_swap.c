// fill the stack from the arr,

#include "push_swap.h"
#include "printf/ft_printf.h"
#include <stdbool.h>
#include <stdio.h>

//put the int *data in a struct



int main(int ac, char **av)
{
    t_head      *stack_a;
    t_head      *stack_b;
	int	        *data;
    size_t      len;
	// int			index;

    data = 0;
	data = ft_parse(ac, av, data);
    stack_a = NULL;
    stack_b = NULL;
    stack_a = stack_init(stack_a, 'a');
    stack_b = stack_init(stack_b, 'b');
    len = ft_strlen_int(data);
    stack_a->bottom = create_stack(len, data, stack_a);
    // rotate(stack_a);
    // ft_printf("node data ====>%d\n", stack_a->stack_len);
    
    // sa(stack_a);
    // rotate(stack_a);/ reverse_rotate(stack_a);

	
    // printf("sort ===%d\n", issort);
    // ft_putnbr_fd(sort, 1);
    // pa(stack_a, stack_b);
	// pa(stack_a, stack_b);
	// pa(stack_a, stack_b);
    // sort(stack_a, stack_b);

	// index = find_position(stack_a, 6);
    print_stacks(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
	free(data);
	
	return EXIT_SUCCESS;
}
