#include "../push_swap.h"

int	ft_do_rra_rb_b(t_stack **a, t_stack **b, int number)
{
	while (ft_new_place_a(*a, number) > 0)
		rra(a);
	while ((*b)->nb != number)
		rb(b);
	pa(a, b);
	return (-2);
}

int	ft_do_ra_rrb_b(t_stack **a, t_stack **b, int number)
{
	while (ft_new_place_a(*a, number) > 0)
		ra(a);
	while ((*b)->nb != number)
		rrb(b);
	pa(a, b);
	return (-2);
}

int	ft_do_rr_b(t_stack **a, t_stack **b, int number)
{
	while ((*a)->nb != number && ft_new_place_a(*a, number) > 0)
			rr(a, b);
	while ((*a)->nb != number)
			rb(a);
	while (ft_new_place_a(*a, number) > 0)
			ra(b);
	pa(a, b);
	return (-2);
}

int	ft_do_rrr_b(t_stack **a, t_stack **b, int number)
{
	while ((*a)->nb != number && ft_new_place_a(*a, number) > 0)
			rrr(a, b);
	while ((*a)->nb != number)
			rrb(a);
	while (ft_new_place_a(*a, number) > 0)
			rra(b);
	pa(a, b);
	return (-2);
}

int ft_count_and_move_b(t_stack **a, t_stack **b, int move, int number)
{
	if (move > ft_case_rr(*a, *b, number))
		move = ft_do_rr_b(a, b, number);
	if (move > ft_case_rrr(*a, *b, number))
		move = ft_do_rrr_b(a, b, number);
	if (move > ft_case_rra_rb(*a, *b, number))
		move = ft_do_rra_rb_b(a, b, number);
	if (move > ft_case_rar_rb(*a, *b, number))
		move = ft_do_ra_rrb_b(a, b, number);
	return (move);
}