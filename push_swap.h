
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>

/***************** Macros ***************/

# define TRUE 1
# define FALSE 0

/***************** Structs **************/

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
	int				index;
}					t_node;

typedef struct s_head
{
	struct s_node	*top;
	struct s_node	*current;
	struct s_node	*bottom;
	int				stack_len;
	char			name;
}					t_head;

/**************** Declaration ***************/

void				free_stack(t_head *head);
void				rotate(t_head *stack);
int					put_intarr(int *tab);
void				print_stacks(t_head *stack_a, t_head *stack_b);
size_t				ft_strlen_int(int *c);
void				swap(t_head *stack);
void				fill_node(int data, t_head **stack);
void				pop(t_head *stack, unsigned int index);
void				pop_last(t_head *stack);
void				pa(t_head *stack_a, t_head *stack_b);
void				pb(t_head *stack_a, t_head *stack_b);
void				reverse_rotate(t_head *stack);
bool				is_sort(t_head *stack);
void				matrix_free(char **matrix);

void				sort_index(t_head *stack, t_node *new_node);
/*-------------- Parsing --------------------*/
// int *parse_multi(int ac, char **av, int *data);
// int *parse_string(int ac, char **av, int *data);
t_head				*ft_parse(int ac, char **av);
void				rotate(t_head *stack);
t_node				*create_stack(int len, char **arr, t_head *stack);
bool				is_duped(t_node *node);
t_head				*ft_parse(int ac, char **av);
int					lst_size(t_node *lst);
bool				already_sorted(t_node *node);
bool				check_number(char *str);

/*-------------- mandatory --------------------*/
bool				sort_above_five(t_head *stack_a, t_head *stack_b);
t_node				*create_node(int data, int index);
bool				sort(t_head *stack_a, t_head *stack_b);
bool				sort_two(t_head *stack);
int					put_intarr(int *tab);
void				sa(t_head *stack_a);
void				sb(t_head *stack_b);
t_head				*stack_init(char c);

#endif
