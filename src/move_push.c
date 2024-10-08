#include "../push_swap.h"

void	ft_stack_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_stack_push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	ft_stack_push(a, b);
	ft_printf("pb\n");
}
