/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:45:40 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:45:41 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_stack *stack)
{
	int	len;

	len = stack->len_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->len_a++;
	stack->a[0] = stack->b[0];
	len = 1;
	while (len < stack->len_b)
	{
		stack->b[len - 1] = stack->b[len];
		len++;
	}
	stack->len_b--;
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack *stack)
{
	int	len;

	len = stack->len_b;
	while (len > 0)
	{
		stack->b[len] = stack->b[len - 1];
		len--;
	}
	stack->len_b++;
	stack->b[0] = stack->a[0];
	len = 1;
	while (len < stack->len_a)
	{
		stack->a[len - 1] = stack->a[len];
		len++;
	}
	stack->len_a--;
	ft_printf("pb\n");
	return (1);
}
