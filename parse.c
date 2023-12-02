

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
	while (argv[i]){
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
	printf("len_argc = %d\n", len_argc(&argv[1]));
    int *result = (int*)malloc(13 * sizeof(int));
    if (result == NULL)
        exit(EXIT_FAILURE);

    int size = 0;

    // Loop through command line arguments using while loop
    int i = 1;
    while (i < argc) {
        char *token = argv[i];

        // Convert string to integer and handle errors
        while (*token != '\0')
		{
            int value = strtol(token, &token, 10);
            result[size] = value;
            (size)++;

            // Skip spaces and tabs
            while (*token == ' ' || *token == '\t')
                token++;
        }
        i++;
    }
    return result;
}

// int main(int argc, char *argv[]) {
//     int size;
//     int *array = parse_args(argc, argv, &size);

//     // Print the parsed array using while loop
//     int i = 0;
//     printf("Parsed Array: ");
//     while (i < size) {
//         printf("%d ", array[i]);
//         i++;
//     }
//     printf("\n");

//     // Don't forget to free the allocated memory
//     free(array);

//     return 0;
// }


int *ft_parse(int ac, char **av, int *data)
{
	if (ac == 0)
		ft_putstr_fd("Error\n", 1);
    if (ac >= 1)
        data = parse_args(ac, av);
		printf("data = %d\n", data[0]);
		put_intarr(data);
	// if (is_duped(data) == TRUE)
	// 	ft_putstr_fd("Error\n", 1);
	//to fix.

    return (data);
}
