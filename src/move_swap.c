/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:45:58 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:45:59 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stack_swap(int *stack)
{
	int		tmp;

	if (!stack[0] || !stack[1])
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	sa(t_stack *a)
{
	ft_stack_swap(a->a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	ft_stack_swap(b->b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	ft_stack_swap(a->a);
	ft_stack_swap(b->b);
	ft_printf("ss\n");
}
