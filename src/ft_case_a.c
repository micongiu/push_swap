#include "../push_swap.h"

int	ft_case_rr_a(t_stack *a, t_stack *b, int number)
{
	int	i;

	i = ft_new_place_a(a, number);
	if (i < ft_find_index(b, number))
		i = ft_find_index(b, number);
	return (i);
}

int	ft_case_rrr_a(t_stack *a, t_stack *b, int number)
{
	int	i;

	i = 0;
	if (ft_new_place_a(a, number))
		i = ft_stack_size(a) - ft_new_place_a(a, number);
	if ((i < (ft_stack_size(b) - ft_find_index(b, number))) && ft_find_index(b, number))
		i = ft_stack_size(b) - ft_find_index(b, number);
	return (i);
}

int	ft_case_ra_rrb_a(t_stack *a, t_stack *b, int number)
{
	int	i;

	i = 0;
	if (ft_find_index(b, number))
		i = ft_stack_size(b) - ft_find_index(b, number);
	i = ft_new_place_a(a, number) + i;
	return (i);
}

int	ft_case_rra_rb_a(t_stack *a, t_stack *b, int number)
{
	int	i;

	i = 0;
	if (ft_new_place_a(a, number))
		i = ft_stack_size(a) - ft_new_place_a(a, number);
	i = ft_find_index(b, number) + i;
	return (i);
}

int	find_cheapst_nb_to_move_a(t_stack *a, t_stack *b)
{
	int		move;
	t_stack	*tmp;

	tmp = b;
	move = 0;
	while (tmp)
	{
		if (move > ft_case_rr_a(a, b, tmp->nb))
			move = ft_case_rr_a(a, b, tmp->nb);
		if (move > ft_case_rrr_a(a, b, tmp->nb))
			move = ft_case_rrr_a(a, b, tmp->nb);
		if (move > ft_case_rra_rb_a(a, b, tmp->nb))
			move = ft_case_rra_rb_a(a, b, tmp->nb);
		if (move > ft_case_ra_rrb_a(a, b, tmp->nb))
			move = ft_case_ra_rrb_a(a, b, tmp->nb);
		tmp = tmp->next;
	}
	return (move);
}

void	ft_3_left_in_a(t_stack **a, t_stack **b)
{
	int	move;
	t_stack	*tmp;

	move = 0;
	while (ft_stack_size(*a) > 3 && !ft_is_sort(*a))
	{
		tmp = *a;
		move = find_cheapst_nb_to_move(*a, *b);
		while (tmp)
		{
			if (ft_count_and_move_a(a, b, move, tmp->nb) == -2)
				break ;
			else
				tmp = tmp->next;
		}
	}
}

void	ft_push_back_in_a(t_stack **a, t_stack **b)
{
	int	move;
	t_stack	*tmp;

	move = 0;
	while (a)
	{
		tmp = *a;
		move = find_cheapst_nb_to_move_a(*a, *b);
		while (tmp)
		{
			if (ft_count_and_move_b(a, b, move, tmp->nb) == -2)
				break ;
			else
				tmp = tmp->next;
		}
		(*a) = (*a)->next;
	}
}