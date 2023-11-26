

#include "libft/libft.h"
#include "push_swap.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

int	count_space(char *s)
{
	int i = 0;
	int j = 0;

	while (s[i])
	{
		if (s[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

int	to_int(char c)
{
	return (c - '0');
}

// char	*buffer_args(int ac, char **av)
// {
// 	int	i = 1;
// 	int j = 0;
// 	char	*buffer;
// 	size_t		string_av_len;
//
// 	string_av_len = ft_strlen((char *)av[1]);
// 	buffer = (char *)malloc(sizeof(char) * string_av_len);
// 	if (!buffer)
// 		return (NULL);
// 	// struct containing stack size
// 	
// 	printf("stop\n");
//
// 		while (av[i][j] != '\0')
// 		{
// 			if (av[i][j] >= '0' && av[i][j] <= '9')
// 				buffer[j] = av[i][j];
// 			if (av[i][j] == ' ')
// 				buffer[j] = ' ';
// 			j++;
// 		}
// 		return buffer;
// }

// int	*arr_buffer(char *buffer, int len)
// {
// 	int i = 0;
// 	int j = 0;
// 	int	*arr = malloc(sizeof(int) * len);
// 	if (!arr)
// 		return (NULL);
//
// 	while (arr[j])
// 	{
//
// 		while (buffer[i] != '\0')
// 		{
// 			if (buffer == ' ')
// 			{
// 				arr[j] = to_int(buffer[i]);
// 				if (ft_isnum(buffer[i + 1]))
// 				{
// 					
// 					arr[j] = to_int(buffer[i]);
// 				}
// 			}
// 			i++;
// 		}
// 		i++;
// 	}
// 	return (arr);
// }

size_t	ft_strlen_int(int *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int arr_len(int *arr)
{
    int length = 0;
    while (*arr) {
        arr++;
        length++;
    }
    return length;
}

// t_parse t_parse_init(int ac, t_parse data)
// {
//     int i;
//
//     i = 0;
//     data.ac = ac;
//     data.parse_arr = (int *) malloc(sizeof(int) * ac + 1); 
//     if (!data.parse_arr)
//         exit (1);
//     // function to free everything in place of exit
//     return (data);
// }

int *ft_puttab(char **tab)
{
    int i;

    i = -1;
    if (!tab)
        return (NULL);
    while (tab[++i])
        ft_printf("Index = %d | %s\n", i, tab[i]);
    return (NULL);
}

//function to auto_print sizeof;


int *parse_string(int ac, char **av, int *data)
{
    char    **tmp_str;
    int i;
    int j;

    i = 0;
    tmp_str = ft_split(av[1], ' ');

    data = (int *) malloc(sizeof(int) * ac + 1); 
    if (!data)
        exit (1);
    // printf("%s\n", tmp_str[1]);
    while (i + 1 < ac)
    {
        data[i] = ft_atoi(tmp_str[i]);
        i++;
        ft_printf("%d", data[i]);
    }
    // printf("STOP\n===============%d", len_of_int_string(data.parse_arr));
    // free two d array, free arr, assign null
    return (data);
}
int main(int ac, char **av)
{
    int *data;
    int i = 0;

    if (ac == 2)
        parse_string(ac, av, data);
    if (ac > 2)
        return (0);
    return EXIT_SUCCESS;
}
