

#include "./push_swap.h"


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int* parseArguments(int argc, char *argv[], int *size) {
    // Allocate memory for the array
    int *result = (int*)malloc(argc * sizeof(int));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Initialize size to 0
    *size = 0;

    // Loop through command line arguments using while loop
    int i = 1;
    while (i < argc) {
        char *token = argv[i];

        // Convert string to integer and handle errors
        while (*token != '\0') {
            int value = strtol(token, &token, 10);
            result[*size] = value;
            (*size)++;

            // Skip spaces and tabs
            while (*token == ' ' || *token == '\t') {
                token++;
            }
        }

        // Increment loop variable
        i++;
    }

    return result;
}

int main(int argc, char *argv[]) {
    int size;
    int *array = parseArguments(argc, argv, &size);

    // Print the parsed array using while loop
    int i = 0;
    printf("Parsed Array: ");
    while (i < size) {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    // Don't forget to free the allocated memory
    free(array);

    return 0;
}


// int *parse_string(int ac, char **av, int *data)
// {
//     char    **tmp_str;
//     int i;
//     int     len;

//     i = 0;
//     tmp_str = ft_split(av[1], ' ');
//     if (tmp_str == NULL)
//         return (NULL);

//     while (tmp_str[i])
//         len = i++;
//     data = (int *) malloc(sizeof(int) * ac - 2); 
//     if (!data)
//         return (NULL);
//     i = 0;
//     while (1)
//     {
//         if ((i - 1) == len)
//             break;
//         data[i] = ft_atoi(tmp_str[i]);
//         i++;
//     }

//     // printf("STOP\n===============%d", len_of_int_string(data.parse_arr));
//     // free two d array, free arr, assign null
//     return (data);
// }

// int *parse_multi(int ac, char **av, int *data)
// {
//     int i;
//     int j;
//     int len;

//     len = ac;
//     data = (int *)malloc((ac - 2) * sizeof(int));
//     i = 0;
//     if (!data)
//         return (NULL);
//     j = 1;
//     while (j < len)
//     {
//         if (i == len)
//             break;
//         data[i] = ft_atoi(av[j]);
//         i++;
//         j++;
//     }
//     return (data);
// }

// int *ft_parse(int ac, char **av, int *data)
// {
//     if (ac > 2)
//         data = parse_multi(ac, av, data);
//     else if (ac == 2)
//         data = parse_string(ac, av, data);
//     else
//         return (NULL);
//     return (data);
// }
