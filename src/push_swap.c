/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <micongiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:54:33 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/05 16:54:56 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		ft_error();
	if (!argv[1][0])
		ft_error();
	if (argc == 2)
		a = ft_init_argc_2(argv);
	else
		a = ft_init_argc_n(argv);
	if (!ft_check_dup(a))
		ft_error_free(&a, NULL);
	ft_sort(&a);
	free_stack(&a);
	return (1);
}
