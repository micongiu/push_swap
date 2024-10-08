/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:45:45 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:45:46 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stack_reverse_rotate(int *stack, int i)
{
	int	len;
	int	tmp;

	tmp = stack[i - 1];
	len = i;
	while (len > 0)
	{
		stack[len] = stack[len - 1];
		len--;
	}
	stack[0] = tmp;
}

void	rra(t_stack *a)
{
	ft_stack_reverse_rotate(a->a, a->len_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	ft_stack_reverse_rotate(b->b, b->len_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_stack_reverse_rotate(a->a, a->len_a);
	ft_stack_reverse_rotate(b->b, b->len_b);
	ft_printf("rrr\n");
}
