

#include "./push_swap.h"

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
    if (!data)
        return (NULL);
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
    data = (int *)malloc((ac - 2) * sizeof(int));
    i = 0;
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

int *ft_parse(int ac, char **av, int *data)
{
    if (ac > 2)
        data = parse_multi(ac, av, data);
    else if (ac == 2)
        data = parse_string(ac, av, data);
    else
        return (NULL);
    return (data);
}
