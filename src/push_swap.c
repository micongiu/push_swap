/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <micongiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:54:33 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:38:33 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		ft_error();
	if (!argv[1][0])
		ft_error();
	if (argc == 2)
		stack = ft_init_argc_2(argv);
	else
		stack = ft_init_argc_n(argv);
	ft_check_dup(stack, stack->len_b);
	ft_sort(stack);
	free_stack(stack);
	return (1);
}
