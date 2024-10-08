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
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


int				ft_case_rr_a(t_stack *a, t_stack *b, int c);
int				ft_case_rrr_a(t_stack *a, t_stack *b, int c);
int				ft_case_rra_rb_a(t_stack *a, t_stack *b, int number);
int				ft_case_ra_rrb_a(t_stack *a, t_stack *b, int number);
int				find_cheapst_nb_to_move_a(t_stack *a, t_stack *b);

int				ft_case_rr(t_stack *a, t_stack *b, int c);
int				ft_case_rrr(t_stack *a, t_stack *b, int c);
int				ft_case_rra_rb(t_stack *a, t_stack *b, int number);
int				ft_case_rar_rb(t_stack *a, t_stack *b, int number);
int				find_cheapst_nb_to_move(t_stack *a, t_stack *b);

int				ft_count_and_move_a(t_stack **a, t_stack **b, int move, int number);
int				ft_count_and_move_b(t_stack **a, t_stack **b, int move, int number);

void			ft_error(void);
void			free_matrix(void **matrix);
void			free_stack(t_stack **stack);
void			ft_error_free(t_stack **stack_a, t_stack **stack_b);

t_stack			*ft_stacklast(t_stack *stack);
void			ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack			*ft_stack_new(int new);
t_stack			*ft_stacklast_circ(t_stack *stack);

t_stack			*ft_init_argc_2(char **argv);
t_stack			*ft_init_argc_n(char **argv);
int				ft_is_sort(t_stack *a);

void			ft_sort(t_stack **a);

int				dup_0_or_sign(char *c);
int				is_num_or_sign(char c);
int				ft_check_dup(t_stack *a);
long long int	ft_atoi_swap(const char *str);
int				ft_stack_size(t_stack *stack);

int				ft_max(t_stack *stack);
int				ft_min(t_stack *stack);
int				ft_find_index(t_stack *stack, int number);
int				ft_new_place_b(t_stack *b, int number_to_push);
int				ft_new_place_a(t_stack *a, int number_to_push);

void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);

void			rra(t_stack **a);
void			rrb(t_stack **a);
void			rrr(t_stack **a, t_stack **b);

void			ra(t_stack **a);
void			rb(t_stack **a);
void			rr(t_stack **a, t_stack **b);

void			sa(t_stack **a);
void			sb(t_stack **a);
void			ss(t_stack **a, t_stack **b);

#endif
