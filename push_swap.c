
#include "push_swap.h"

//function that will fill the stack a from argv
t_node	*init_stack(void)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->data = 0;
	head->next = NULL;
	return (head);
}

t_node	*link_node(t_node *node, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	node->next = new_node;
	new_node->data = value;
	new_node->next = NULL;
	return(new_node);
}

//void	print_node(int index, node_t head)

t_node	*create_stack(int size, t_node *head, int debug)
{
	int i = 0;
	t_node	*current_node;

	current_node = NULL;
	head = init_stack();
	if (head == NULL)
		return NULL;
	
	while (i < size)
	{
		current_node = link_node(head, i); 
		if (debug == 1)
			printf("%d\n", current_node->data);
		i++;
	}
	return (head);

}
int	*ft_parse(int ac, char **av)
{
	int	i = 0;
	const char	*buffer;
	size_t		string_av_len;

	string_av_len = ft_strlen(av[1]);
	buffer = (const char *) malloc(sizeof(const char) * string_av_len);
	// struct containing stack size
	
	if (ac == 0)
		return (0);

	if (ac == 1)
	{
		while (av[i] => '0' && av[i] =< '9')
		{
			ft_	
		}

	}
}



int main(int ac, char **av)
{
	t_node	*head;
	t_node	*top_sa;
	t_node	*top_sb;



	top_sb = init_stack();
	top_sa = init_stack();
	top_sa = create_stack(10, top_sa, 1);
	top_sb= create_stack(10, top_sb, 1);
	freeLinkedList(head);
	


	
	return EXIT_SUCCESS;
}
