/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <micongiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:41:33 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/05 16:53:06 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long int	ft_atoi_swap(const char *str)
{
	long long int	result;
	int				sign;

	sign = 1;
	result = 0;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while (*str)
	{
		result = result * 10;
		result += (*str++ - '0');
	}
	return (sign * result);
}

int	ft_check_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nb == tmp->nb)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}

int	is_num_or_sign(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+' || c == 32)
		return (0);
	return (1);
}

int	dup_0_or_sign(char *c)
{
	int	i;

	i = 1;
	while (c[i])
	{
		if (c[i + 1] && c[i - 1] == ' ' && c[i] == '0' && c[i + 1] == '0')
			return (1);
		if (c[i + 1] && c[i - 1] == ' ' && (c[i] == '+' && c[i + 1] == '+'
				|| c[i] == '-' && c[i + 1] == '-'))
			return (1);
		i++;
	}
	return (0);
}
