/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micongiu <micongiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:39:05 by micongiu          #+#    #+#             */
/*   Updated: 2024/10/08 21:46:20 by micongiu         ###   ########.fr       */
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
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}		t_stack;

void			ft_error(void);
void			free_stack(t_stack *stack);
void			free_matrix(void **matrix);
void			free_stack_error(t_stack *stack);

t_stack			*ft_init_argc_2(char **argv);
t_stack			*ft_init_argc_n(char **argv);

void			ft_sort(t_stack *stack);
int				ft_is_sort_desc(int *stack, int len);
int				ft_is_sort(int *stack, int len);

int				dup_0_or_sign(char *c);
int				is_num_or_sign(char c);
void			ft_check_dup(t_stack *stack, int k);
long long int	ft_atoi_swap(const char *str);

int				ft_max(int *stack, int len);
int				ft_min(t_stack *stack);
int				find_index(int *stack, int nb);
void			ft_sort_3(t_stack *a);

void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);

void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);

int				pa(t_stack *stack);
int				pb(t_stack *stack);

void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

void			small_sort(int *tmp_stk, int dim);
int				quick_sort_a(t_stack *stack, int dim, int count_r);
int				if_push(t_stack *stack, int dim, int f);

#endif
