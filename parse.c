

#include "libft/libft.h"
#include "push_swap.h"

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

size_t	ft_strlen_int(int *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int put_intarr(int *tab)
{
    int i;

    i = 0;
    if (!tab)
        return (0);
    while (tab[i++])
    {
        if (!tab[i])
            break;
        ft_printf("Index = %d | %d\n", i, tab[i]);

    }
    return (i);
}

int ft_puttab(char **tab)
{
    int i;

    i = -1;
    if (!tab)
        return (0);
    while (tab[++i])
        ft_printf("Index = %d | %s\n", i, tab[i]);
    return (i);
}

//function to auto_print sizeof;
int *strdup_int(int *arr)
{
    int i;
    int *dupe;

    i = -1;
    if (!arr)
        return (NULL);
    dupe = (int *)malloc(sizeof(arr)); 
    if (!dupe)
        return (NULL);
    while (arr[++i])
        dupe[i] = arr[i];
    return (dupe);
}

bool    is_duped(int *arr)
{
    int i;
    int j;
    int *tmp_str;

    i = 0;
    j = 0;
    tmp_str = strdup_int(arr);
    while (arr[i] && tmp_str)
    {
        while (tmp_str[j])
        {
            if (tmp_str[j] == arr[i])
                return (0);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

int *parse_string(int ac, char **av, int *data)
{
    char    **tmp_str;
    int i;
    int     len;

    i = 0;
    tmp_str = ft_split(av[1], ' ');

    while (tmp_str[i])
        len = i++;
    data = (int *) malloc(sizeof(int) * ac - 2); 
    ft_printf("len = %d\n", len);
    if (!data)
        exit (1);
    i = 0;
    while (1)
    {
        if ((i - 1) == len)
            break;
        data[i] = ft_atoi(tmp_str[i]);
        i++;
    }

    // printf("STOP\n===============%d", len_of_int_string(data.parse_arr));
    // free two d array, free arr, assign null
    return (data);
}

int *parse_multi(int ac, char **av, int *data)
{
    int i;
    int j;
    int len;

    len = ac;
    data = (int *)ft_calloc(len, sizeof(int));
    if (!data)
        return (NULL);
    j = 1;
    while (j < len)
    {
        if (i == len)
            break;
        data[i] = ft_atoi(av[j]);
        i++;
        j++;
    }
    return (data);
}

int main(int ac, char **av) {
    int *data;

    data = 0;
    if (ac == 2)
        data = parse_string(ac, av, data);
    if (ac > 2)
        data = parse_multi(ac, av, data);

    put_intarr(data);
    return EXIT_SUCCESS;
}
