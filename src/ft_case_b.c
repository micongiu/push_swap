#include "../push_swap.h"

int	ft_case_rr(t_stack *a, t_stack *b, int number)
{
	int	i;

	i = ft_new_place_b(b, number);
	if (i < ft_find_index(a, number))
		i = ft_find_index(a, number);
	return (i);
}

int	ft_case_rrr(t_stack *a, t_stack *b, int number)
{
	int	i;

	i = 0;
	if (ft_new_place_b(b, number))
		i = ft_stack_size(b) - ft_new_place_b(b, number);
	if ((i < (ft_stack_size(a) - ft_find_index(a, number))) && ft_find_index(a, number))
		i = ft_stack_size(a) - ft_find_index(a, number);
	return (i);
}

int	ft_case_rra_rb(t_stack *a, t_stack *b, int number)
{
	int	i;

	i = 0;
	if (ft_find_index(a, number))
		i = ft_stack_size(a) - ft_find_index(a, number);
	i = ft_new_place_b(b, number) + i;
	return (i);
}

int	ft_case_rar_rb(t_stack *a, t_stack *b, int number)
{
	int	i;

	i = 0;
	if (ft_new_place_b(b, number))
		i = ft_stack_size(b) - ft_new_place_b(b, number);
	i = ft_find_index(a, number) + i;
	return (i);
}

int	find_cheapst_nb_to_move(t_stack *a, t_stack *b)
{
	int		move;
	t_stack	*tmp;

	tmp = a;
	move = 0;
	while (tmp)
	{
		if (move > ft_case_rr(a, b, tmp->nb))
			move = ft_case_rr(a, b, tmp->nb);
		if (move > ft_case_rrr(a, b, tmp->nb))
			move = ft_case_rrr(a, b, tmp->nb);
		if (move > ft_case_rra_rb(a, b, tmp->nb))
			move = ft_case_rra_rb(a, b, tmp->nb);
		if (move > ft_case_rar_rb(a, b, tmp->nb))
			move = ft_case_rar_rb(a, b, tmp->nb);
		tmp = tmp->next;
	}
	return (move);
}
