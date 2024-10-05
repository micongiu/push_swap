/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <micongiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:39:05 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/05 16:27:02 by micongiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	long			nb;
	long			pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void			ft_error(void);
void			free_matrix(void **matrix);
void			free_stack(t_stack **stack);
void			ft_error_free(t_stack **stack_a, t_stack **stack_b);

t_stack			*ft_stacklast(t_stack *stack);
void			ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack			*ft_stack_new(int new);

t_stack			*ft_init_argc_2(char **argv);
t_stack			*ft_init_argc_n(char **argv);

int				dup_0_or_sign(char *c);
int				is_num_or_sign(char c);
int				ft_check_dup(t_stack *a);
long long int	ft_atoi_swap(const char *str);

#endif
