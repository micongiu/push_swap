/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:45:19 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:45:21 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max(int *stack, int len)
{
	int	i;
	int	max;

	i = 0;
	max = stack[i];
	while (i < len)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	find_index(int *stack, int nb)
{
	int	i;

	i = 0;
	while (stack[i] != nb)
		i++;
	return (i);
}

void	small_sort(int *tmp_stk, int dim)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < dim)
	{
		j = i + 1;
		while (j < dim)
		{
			if (tmp_stk[i] > tmp_stk[j])
			{
				tmp = tmp_stk[i];
				tmp_stk[i] = tmp_stk[j];
				tmp_stk[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	if_push(t_stack *stack, int dim, int f)
{
	if (f == 1)
		pb(stack);
	else if (f == 0)
		pa(stack);
	dim--;
	return (dim);
}
