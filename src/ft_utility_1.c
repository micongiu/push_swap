#include "../push_swap.h"

int	ft_max(t_stack *stack)
{
	int		max;

	max = -2147483648;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	return (max);
}

int	ft_min(t_stack *stack)
{
	int	min;

	min = 2147483647;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

int	ft_find_index(t_stack *stack, int number)
{
	int	index;

	index = 1;
	while (stack->nb != number)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

int	ft_new_place_b(t_stack *b, int number_to_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (number_to_push > b->nb && number_to_push < ft_stacklast(b)->nb)
		i = 0;
	else if (number_to_push > ft_max(b) || number_to_push < ft_min(b))
	{
		// printf("ciao\n");
		i = ft_find_index(b, ft_max(b));

	}
	else
	{
		tmp = b->next;
		while (b->nb < number_to_push || tmp->nb > number_to_push)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

int	ft_new_place_a(t_stack *a, int number_to_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (number_to_push < a->nb && number_to_push > ft_stacklast(a)->nb)
		i = 0;
	else if (number_to_push > ft_max(a) || number_to_push < ft_min(a))
		i = ft_find_index(a, ft_min(a));
	else
	{
		tmp = a->next;
		while (a->nb > number_to_push || tmp->nb < number_to_push)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	printf("ciao\n");
	return (i);
}
