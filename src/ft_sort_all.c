#include "../push_swap.h"

void	ft_sort_3(t_stack **a)
{
	int	max_index; 

	max_index = ft_find_index((*a), ft_max(*a));
	if (max_index == 1) 
		ra(a);
	else if (max_index == 2)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}


void	push_from_max_to_min(t_stack **a, t_stack **b, int max, int min)
{
	int	i;

	i = 0;
	while (max > i)
	{
		ra(a);
		i++;
	}
	pb(a, b);
	i = 1;
	while (min - max > i)
	{
		ra(a);
		i++;
	}
	pb(a, b);
}

void	ft_sort_5(t_stack **a)
{
	t_stack	*b;
	int		min;
	int		max;

	b = NULL;
	min = ft_find_index(a, ft_min(a));
	max = ft_find_index(a, ft_max(a));
	if (max > min)
		push_from_max_to_min(a, &b, max, min);
	else
		push_from_min_to_max(a, &b, min, max);
	ft_sort_3(a);
	if (b->nb > b->next->nb)
		ft_sb(b);
	ft_pa(a, b);
	ft_pa(a, b);
	ft_ra(a);
}

void	ft_sort_n(t_stack **a)
{
	t_stack	*b;
	int		index;

	b = NULL;
	index = 0;
	pb(a, &b);
	pb(a, &b);
	if (b->nb < b->next->nb)
		sb(b);
	if (!ft_is_sort(*a))
		ft_sort_3(a);
	ft_push_back_in_a(a, &b);
	index = ft_find_index(*a, ft_min(*a));
	if (index < ft_stack_size(*a) / 2)
		{
			while ((*a)->nb != ft_min(*a))
				ra(a);
		}
		else
		{
			while ((*a)->nb != ft_min(*a))
				rra(a);
		}		
}

void	ft_sort(t_stack **a)
{
	int		size;

	if (ft_is_sort(*a) == 1)
		return ;
	size = ft_stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		ft_sort_3(a);
	else if (size == 5)
		ft_sort_5(a);
	else
		ft_sort_n(a);
}
