/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <micongiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:51:41 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:40:47 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stack(int argc, char **tmp, int i, t_stack *stack)
{
	int				j;
	long long int	nb;

	stack->a = (int *)ft_calloc(sizeof(int), (argc));
	stack->b = (int *)ft_calloc(sizeof(int), (argc));
	j = 0;
	while (i < argc)
	{
		nb = ft_atoi_swap(tmp[i]);
		if (nb > 2147483647 || nb < -2147483648)
			free_stack_error(stack);
		stack->a[j] = nb;
		i++;
		j++;
	}
	stack->len_a = j;
	stack->len_b = 0;
}

t_stack	*ft_init_argc_2(char **argv)
{
	char			**tmp;
	int				i;
	t_stack			*stack;

	i = 0;
	tmp = NULL;
	stack = ft_calloc(sizeof(t_stack), 1);
	while (argv[1][i])
		if (is_num_or_sign(argv[1][i++]) == 1)
			ft_error();
	if (dup_0_or_sign(argv[1]) == 1)
		ft_error();
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
		i++;
	fill_stack(i, tmp, 0, stack);
	free_matrix((void **)tmp);
	return (stack);
}

void	ft_init_argc_n_help(char **argv)
{
	int				j;

	j = 0;
	while (argv[1][j])
		if (is_num_or_sign(argv[1][j++]) == 1)
			ft_error();
	if (dup_0_or_sign(argv[1]) == 1)
		ft_error();
}

t_stack	*ft_init_argc_n(char **argv)
{
	int				i;
	int				j;
	t_stack			*stack;

	i = 0;
	ft_init_argc_n_help(argv);
	stack = ft_calloc(sizeof(t_stack), 1);
	while (argv[++i])
	{
		j = 0;
		if (!argv[i][0])
			ft_error();
		while (argv[i][j])
			if (is_num_or_sign(argv[i][j++]) == 1)
				ft_error();
		if (dup_0_or_sign(argv[i]) == 1)
			ft_error();
	}
	fill_stack(i, argv, 1, stack);
	return (stack);
}
