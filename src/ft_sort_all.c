/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:45:32 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:45:33 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sort(int *stack, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (stack[i - 1] > stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort_desc(int *stack, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (stack[i - 1] < stack[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_sort_3(t_stack *a)
{
	int	max_index;

	max_index = find_index((a->a), ft_max(a->a, a->len_a));
	if (max_index == 0)
		ra(a);
	else if (max_index == 1)
		rra(a);
	if (a->a[0] > a->a[1])
		sa(a);
}

void	ft_sort(t_stack *stack)
{
	if (stack->len_a == 2)
		sa(stack);
	else if (stack->len_a)
		ft_sort_3(stack);
	else
		quick_sort_a(stack, stack->len_a, 0);
}
