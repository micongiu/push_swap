#include "../push_swap.h"

void	ft_stack_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;

}

void	sa(t_stack **a)
{
	ft_stack_swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	ft_stack_swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	ft_stack_swap(a);
	ft_stack_swap(b);
	ft_printf("ss\n");
}
