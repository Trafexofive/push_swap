

#include "./push_swap.h"

int counter(char **spl){
	int i;

	i = 0;
	while (spl[i])
		i++;
	// printf("i = %d\n", i);
	return (i);
}

int len_argc(char **argv)
{
	int i;
	int len;
	char **spl;

	i = 0;
	len = 0;
	while (argv[i])
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		spl = ft_split(argv[i], ' ');
		len += counter(spl);
		i++;
		// matrix_free(spl);
	}
	return (len);
}

int* parse_args(int argc, char *argv[])
{
    // Allocate memory for the array
    int *result; = (int*)malloc(len_argc(argv) * sizeof(int));
    if (result == NULL)
        exit(EXIT_FAILURE);

    int size = 0;

    int i = 1;
    while (i < argc) {

        i++;
    }
    return result;
}

int *ft_parse(int ac, char **av, int *data)
{
	if (ac == 0)
		ft_putstr_fd("Error\n", 1);
    if (ac >= 1)
        data = parse_args(ac, av);
	// if (is_duped(data) == TRUE)
	// 	ft_putstr_fd("Error\n", 1);
	//to fix.

    return (data);
}
