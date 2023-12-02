

#include "./push_swap.h"

int	counter(char **spl)
{
	int	i;

	i = 0;
	while (spl && spl[i])
		i++;
	return (i);
}

bool	parse_args(int ac, char *av[], t_head *stack)
{
	char	**spl;
	int		size;
	int		i;
	int		j;

	i = 1; 
	while (i < ac)
	{
		spl = ft_split(av[i], ' ');
		size = counter(spl);
		j = 0;
		while (j < size)
		{
			if (check_number(spl[j]) == FALSE)
				return (matrix_free(spl), true);
			fill_node(ft_atoi(spl[j]), &stack);
			j++;
		}
		matrix_free(spl);
		i++;
	}
	return (false);
}

bool	str_is_space(char *str)
{
	if (!*str)
		return (true);
	while (*str)
	{
		if (!ft_strchr("\t\n\v\f\r ", *str))
			return (false);
		str++;
	}
	return (true);
}

bool	check_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (str_is_space(av[i]))
			return (true);
		i++;
	}
	return (false);
}

t_head	*ft_parse(int ac, char **av)
{
	t_head	*data;

	if (ac == 0)
		return NULL;
	data = stack_init('a');
	if (check_av(av) || parse_args(ac, av, data) || is_duped(data->top))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(data);
		exit(EXIT_FAILURE);
	}
	if (already_sorted(data->top))
	{
		free_stack(data);
		exit(EXIT_SUCCESS);
	}
	data->stack_len = lst_size(data->top);
	return (data);
}
