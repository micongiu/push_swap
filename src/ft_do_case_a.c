#include "../push_swap.h"

int	ft_do_rr_a(t_stack **a, t_stack **b, int number)
{
	while ((*a)->nb != number && ft_new_place_b(*b, number) > 0)
			rr(a, b);
	while ((*a)->nb != number)
			ra(a);
	while (ft_new_place_b(*b, number) > 0)
			rb(b);
	pb(a, b);
	return (-2);
}

int	ft_do_rrr_a(t_stack **a, t_stack **b, int number)
{
	while ((*a)->nb != number && ft_new_place_b(*b, number) > 0)
			rrr(a, b);
	while ((*a)->nb != number)
			rra(a);
	while (ft_new_place_b(*b, number) > 0)
			rrb(b);
	pb(a, b);
	return (-2);
}

int	ft_do_rra_rb_a(t_stack **a, t_stack **b, int number)
{
	while ((*a)->nb != number)
		rra(a);
	while (ft_new_place_b(*b, number) > 0)
		rb(b);
	pb(a, b);
	return (-2);
}

int	ft_do_ra_rrb_a(t_stack **a, t_stack **b, int number)
{
	while ((*a)->nb != number)
		ra(a);
	while (ft_new_place_b(*b, number) > 0)
		rb(b);
	pb(a, b);
	return (-2);
}

int ft_count_and_move_a(t_stack **a, t_stack **b, int move, int number)
{
	if (move > ft_case_rr_a(*a, *b, number))
		move = ft_do_rr_a(a, b, number);
	if (move > ft_case_rrr_a(*a, *b, number))
		move = ft_do_rrr_a(a, b, number);
	if (move > ft_case_rra_rb_a(*a, *b, number))
		move = ft_do_rra_rb_a(a, b, number);
	if (move > ft_case_ra_rrb_a(*a, *b, number))
		move = ft_do_ra_rrb_a(a, b, number);
	return (move);
}