#include "../push_swap.h"

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}

t_stack	*ft_stack_new(int new)
{
	t_stack	*new_stack;

	new_stack = ft_calloc(sizeof (t_stack), 1);
	if (!new)
		ft_error();
	new_stack->nb = new;
	new_stack->next = NULL;
	return (new_stack);
}

void	free_matrix(void **matrix)
{
	size_t	i;

	i = 0;
	if (matrix == NULL)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void ft_error_free(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	ft_error();
}

void	ft_error(void)
{	
	ft_printf("Error\n");
	exit(1);
}

long long int	ft_atoi_swap(const char *str)
{
	long long int	result;
	int				sign;

	sign = 1;
	result = 0;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while (*str)
	{
		result = result * 10;
		result += (*str++ - '0');
	}
	return (sign * result);
}

int	ft_check_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nb == tmp->nb)
				ft_error_free(&a, NULL);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}

int	is_num_or_sign(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (0);
	return (1);
}

int	dup_0_or_sign(char *c)
{
	int	i;

	i = 0;
	while (c)
		if (c[i - 1] == ' ' && c[i] == '0' && c[i + 1] == '0')
			return (1);
		if (c[i - 1] == ' ' && (c[i] == '+' && c[i + 1] == '+' ||
			c[i] == '-' && c[i + 1] == '-'))
			return (1);
		i++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_start();
	if (argc < 2)
		ft_error;
	if (argc == 2)
	{
		char			**tmp;
		int				i;
		long long int	nb;

		i = 0;
		nb = 0;
		while (argv[2][i])
			if (is_num_or_sign(argv[2][i++]) == 1)
				ft_error();
		if (dup_0_or_sign(argv[2]) == 1)
			ft_error();
		i = 0;
		tmp = ft_split(argv[1], 32);
		while (tmp[i])
		{
			nb = (ft_atoi_swap(tmp[i]));
			if (nb > 2147483647 || nb < -2147483648)
				ft_error_free(&a, NULL);
			else
				ft_add_back(&a, ft_stack_new(nb));
			i++;
		}
		free_matrix((void **)tmp);
	}
	else
	{
		int				i;
		int				j;
		long long int	nb;
	
		i = 0;
		nb = 0;
		j = 0;
		while (argv[2][j])
			if (is_num_or_sign(argv[2][j++]) == 1)
				ft_error();
		if (dup_0_or_sign(argv[2]) == 1)
			ft_error();
		while (argv[i])
		{
			j = 0;
			while (argv[2][i])
				if (is_num_or_sign(argv[2][j++]) == 1)
					ft_error_free(&a, NULL);
			if (dup_0_or_sign(argv[2]) == 1)
				ft_error_free(&a, NULL);
			nb = (ft_atoi_swap(argv[i]));
			if (nb > 2147483647 || nb < -2147483648)
				ft_error_free(&a, NULL);
			else
				ft_add_back(&a, ft_stack_new(nb));
			i++;
		}
	}
	if (!ft_check_dup(a))
		ft_sort(&a);
	return (1);
}
