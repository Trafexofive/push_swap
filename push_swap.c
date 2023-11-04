
#include "includes/push_swap.h"

//function that will fill the stack a from argv
void	fill_stack(int ac, char **av, node *sa)
{
	exit(EXIT_FAILURE);
}

node	create_stack(int size)
{
	int i = 0;

	while (i < size)
	{

		i++;
	}
}
void	ft_errors(int error)
{
	printf("%s", "error\n");
}

int	*ft_parse(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] != '\n')
	{
		while (argv[i][j])
		{
			printf("%s\n", argv[i][j]);
			j++;
		}

		i++;
	}

}



int main(int ac, char **av)
{
	node	sa;
	

	fill_stack(int ac, char **av, node *sa);


	return EXIT_SUCCESS;
}
