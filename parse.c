

#include "./push_swap.h"


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasValidSign(const char* str) {
    if (*str == '\0') {
        return false;  // Empty string
    }

    if (*str == '+' || *str == '-') {
        str++;
    }

    while (*str >= '0' && *str <= '9')
        str++;
    return *str == '\0';  // Valid sign only if the entire string is consumed as a number
}

bool isValidNumber(const char* str)
{
    if (*str == '+' || *str == '-')
        str++;  // Skip the sign if present
    while (*str >= '0' && *str <= '9')
        str++;
    return *str == '\0';  // Valid number only if the entire string is consumed as a number
}

int* parseArgsToIntArray(int argc, char* argv[], int* arraySize) {
    int count = 0;

    // Count the number of integers in the arguments
    for (int i = 1; i < argc; i++) {
        char* ptr = argv[i];
        int signCount = 0;

        while (*ptr != '\0') {
            if ((*ptr == '+' || *ptr == '-') && (*(ptr + 1) >= '0' && *(ptr + 1) <= '9') && hasValidSign(ptr)) {
                signCount++;
                if (signCount > 1) {
                    fprintf(stderr, "Error: Number has more than one sign: %s\n", argv[i]);
                    exit(EXIT_FAILURE);
                }
                count++;
                ptr += 2; // Skip the '+' or '-' and the first digit
                while (*ptr >= '0' && *ptr <= '9') {
                    ptr++;
                }
            } else if (*ptr >= '0' && *ptr <= '9' && isValidNumber(ptr)) {
                count++;
                while (*ptr >= '0' && *ptr <= '9') {
                    ptr++;
                }
            } else {
                fprintf(stderr, "Error: Invalid character in argument: %s\n", argv[i]);
                exit(EXIT_FAILURE);
            }
        }
    }

    // Allocate memory for the integer array and signs array
    int* resultArray = (int*)malloc(count * sizeof(int));
    char* signsArray = (char*)malloc(count * sizeof(char));
    if (resultArray == NULL || signsArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Parse the integers from the arguments and store them in the array along with signs
    int index = 0;

    for (int i = 1; i < argc; i++) {
        char* ptr = argv[i];
        int signCount = 0;

        while (*ptr != '\0') {
            if ((*ptr == '+' || *ptr == '-') && (*(ptr + 1) >= '0' && *(ptr + 1) <= '9') && hasValidSign(ptr)) {
                signCount++;
                if (signCount > 1) {
                    fprintf(stderr, "Error: Number has more than one sign: %s\n", argv[i]);
                    exit(EXIT_FAILURE);
                }
                signsArray[index] = *ptr;
                resultArray[index++] = atoi(ptr);
                ptr += 2; // Skip the '+' or '-' and the first digit
                while (*ptr >= '0' && *ptr <= '9') {
                    ptr++;
                }
            } else if (*ptr >= '0' && *ptr <= '9' && isValidNumber(ptr)) {
                signsArray[index] = '+';
                resultArray[index++] = atoi(ptr);
                while (*ptr >= '0' && *ptr <= '9') {
                    ptr++;
                }
            } else {
                printf("Error: Invalid character in argument: %s\n", argv[i]);
                exit(EXIT_FAILURE);
            }
        }
    }

    // Set the array size if requested
    if (arraySize != NULL) {
        *arraySize = count;
    }

    // Free the allocated memory for signsArray as it is not needed outside the function
    free(signsArray);

    return resultArray;
}

int main(int argc, char* argv[]) {
    int arraySize;
    int* resultArray = parseArgsToIntArray(argc, argv, &arraySize);

    printf("Array Size: %d\n", arraySize);
    printf("Parsed Integers with Signs: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", resultArray[i]);
    }

    // Don't forget to free the allocated memory
    free(resultArray);

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
