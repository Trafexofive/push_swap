
#include "includes/push_swap.h"

void	init_stack(stack *s, int size)
{
	s->elements = malloc(size * sizeof(int));
	s->size = size;
	s->top = -1;
}

void push(stack *s, int element) 
{
  if (s->top + 1 >= s->size)
	{
		printf("Error: stack overflow!\n");
		exit(1);
	}

	s->top++;
	s->elements[s->top] = element;
}

int pop(stack *s) 
{
	if (s->top == -1)
	{
		printf("Error: stack underflow!\n");
		exit(1);
	}
	int element = s->elements[s->top];
	s->top--;
	return element;
}

void print_stack(stack *s)
{
	int i = s->top;
	while (i >= 0)
	{
		printf("%d ", s->elements[i]);
		i--;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	stack stack_a;
	stack stack_b;

	init_stack(&stack_a, argc - 1);
	init_stack(&stack_b, argc - 1);

  // Read the input stack from the command line.
	int i = 1;
	while (i < argc)
	{
		int element = atoi(argv[i]);
		push(&stack_a, element);
		i++;
	}

  // Sort the stack A.

  // Print the sequence of instructions used to sort the stack A.

  return 0;
}
