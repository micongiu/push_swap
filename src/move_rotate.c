/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:45:52 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:45:53 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stack_rotate(int *stack, int len)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack[0];
	while (++i < len - 1)
		stack[i] = stack[i + 1];
	stack[i] = tmp;
}

void	ra(t_stack *a)
{
	ft_stack_rotate(a->a, a->len_a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	ft_stack_rotate(b->b, b->len_b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ft_stack_rotate(a->a, a->len_a);
	ft_stack_rotate(b->b, b->len_b);
	ft_printf("rr\n");
}
