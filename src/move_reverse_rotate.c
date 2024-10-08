#include "../push_swap.h"

void	ft_stack_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp_last;
	t_stack	*tmp_before_last;
	t_stack	*tmp;

	tmp = *(stack);
	if (!(tmp && tmp->next))
		return ;
	tmp_last = tmp;
	while (tmp_last->next)
	{
		tmp_before_last = tmp_last;
		tmp_last = tmp_last->next;
	}
	tmp_last->next = tmp;
	tmp_before_last->next = NULL;
	*stack = tmp_last;
}

void	rra(t_stack **a)
{
	ft_stack_reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	ft_stack_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_stack_reverse_rotate(a);
	ft_stack_reverse_rotate(b);
	ft_printf("rrr\n");
}
