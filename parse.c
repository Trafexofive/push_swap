

#include "libft/libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

int	count_white_space(char *s)
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

char	*buffer_args(int ac, char **av)
{
	int	i = 1;
	int j = 0;
	char	*buffer;
	size_t		string_av_len;

    (void) ac;
	string_av_len = ft_strlen((char *)av[1]);
	buffer = (char *)malloc(sizeof(char) * string_av_len);
	if (!buffer)
		return (NULL);
	// struct containing stack size
	
	printf("stop\n");

		while (av[i][j] != '\0')
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				buffer[j] = av[i][j];
			if (av[i][j] == ' ')
				buffer[j] = ' ';
			j++;
		}
		return buffer;
}

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

int len_of_int_string(int *arr)
{
    int length = 0;
    while (*arr) {
        arr++;
        length++;
    }
    return length;
}

int main(int ac, char **av)
{
    int i = 0;
    int *parse_arr;


    // while (data[i])
    // {
    //
    //     printf("%d\n", data[i]);
    //     i++;
    // }
    return EXIT_SUCCESS;
}
