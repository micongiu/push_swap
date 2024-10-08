/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:45:09 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:45:12 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quick_sort_3_a_b(t_stack *stack, int dim)
{
	if (dim == 3 && stack->len_a == 3)
		ft_sort_3(stack);
	else if (dim == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
	}
	else if (dim == 3)
	{
		while (dim != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (dim == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack);
			else if (dim == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				dim = if_push(stack, dim, 1);
			else if (stack->a[0] > stack->a[1])
				sa(stack);
			else if (dim++)
				pa(stack);
		}
	}
}

int	partition(int *pivot, int *stack, int dim)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = (int *)malloc(sizeof(int) * dim);
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	while (i < dim)
		tmp[j++] = stack[i++];
	small_sort(tmp, dim);
	*pivot = tmp[dim / 2];
	free(tmp);
	return (1);
}

int	sort_3_b(t_stack *stack, int dim)
{
	if (dim == 1)
		pa(stack);
	else if (dim == 2)
	{
		if (stack->b[0] < stack->b[1])
			sb(stack);
		while (dim--)
			pa(stack);
	}
	else if (dim == 3)
	{
		while (dim || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (dim == 1 && stack->a[0] > stack->a[1])
				sa(stack);
			else if (dim == 1
				|| (dim >= 2 && stack->b[0] > stack->b[1])
				|| (dim == 3 && stack->b[0] > stack->b[2]))
				dim = if_push(stack, dim, 0);
			else
				sb(stack);
		}
	}
	return (0);
}

int	quick_sort_b(t_stack *stack, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (!count_r && ft_is_sort_desc(stack->b, dim) == 1)
		while (dim--)
			pa(stack);
	if (dim <= 3)
	{
		sort_3_b(stack, dim);
		return (1);
	}
	numbers = dim;
	if (!partition(&pivot, stack->b, dim))
		return (0);
	while (dim != numbers / 2)
	{
		if (stack->b[0] >= pivot && dim--)
			pa(stack);
		else if (++count_r)
			rb(stack);
	}
	while (numbers / 2 != stack->len_b && count_r--)
		rrb(stack);
	return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(stack, numbers / 2, 0));
}

int	quick_sort_a(t_stack *stack, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (ft_is_sort(stack->a, dim) == 1)
		return (1);
	if (dim <= 3)
	{
		quick_sort_3_a_b(stack, dim);
		return (1);
	}
	numbers = dim;
	if (!count_r && !partition(&pivot, stack->a, dim))
		return (0);
	while (dim != numbers / 2 + numbers % 2)
	{
		if (stack->a[0] < pivot && (dim--))
			pb(stack);
		else if (++count_r)
			ra(stack);
	}
	while (count_r--)
		rra(stack);
	return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(stack, numbers / 2, 0));
	return (1);
}
