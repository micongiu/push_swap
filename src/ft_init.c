/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <micongiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:51:41 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/05 16:40:55 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_init_argc_2(char **argv)
{
	char			**tmp;
	int				i;
	long long int	nb;
	t_stack			*a;

	i = 0;
	nb = 0;
	a = NULL;
	while (argv[1][i])
		if (is_num_or_sign(argv[1][i++]) == 1)
			ft_error();
	if (dup_0_or_sign(argv[1]) == 1)
		ft_error();
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		nb = ft_atoi_swap(tmp[i++]);
		if (nb > 2147483647 || nb < -2147483648)
			ft_error_free(&a, NULL);
		else
			ft_add_back(&a, ft_stack_new(nb));
	}
	free_matrix((void **)tmp);
	return (a);
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
	long long int	nb;
	t_stack			*a;

	i = 0;
	nb = 0;
	a = NULL;
	ft_init_argc_n_help(argv);
	while (argv[++i])
	{
		j = 0;
		if (!argv[i][0])
			ft_error_free(&a, NULL);
		while (argv[i][j])
			if (is_num_or_sign(argv[i][j++]) == 1)
				ft_error_free(&a, NULL);
		if (dup_0_or_sign(argv[i]) == 1)
			ft_error_free(&a, NULL);
		nb = (ft_atoi_swap(argv[i]));
		if (nb > 2147483647 || nb < -2147483648)
			ft_error_free(&a, NULL);
		ft_add_back(&a, ft_stack_new(nb));
	}
	return (a);
}

int	ft_is_sort(t_stack *a)
{
	while (a)
	{
		if (a->next && a->nb > a->next->nb)
			return (0);
		a = a->next;
	}
	return (1);
}
