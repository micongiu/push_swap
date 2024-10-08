/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <micongiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:39:15 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:23:47 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_matrix(void **matrix)
{
	size_t	i;

	i = 0;
	if (matrix == NULL)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	if (stack)
		free(stack);
	exit(0);
}

void	free_stack_error(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	if (stack)
		free(stack);
	ft_error();
	exit(0);
}
