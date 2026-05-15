/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tojorana <tojorana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:40:26 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 09:16:21 by tojorana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*nxt;
}					t_stack;

typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total_ops;
	int				*mode;
}					t_bench;

typedef struct s_flag
{
	int				algo;
	int				mode;
	char			*algo_name;
	char			*complx;
	t_bench			bench;
}					t_flag;

void				rra(t_stack **stack_a, t_bench *bench);
void				rrb(t_stack **stack_b, t_bench *bench);
void				rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void				ra(t_stack **stack_a, t_bench *bench);
void				rb(t_stack **stack_b, t_bench *bench);
void				rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void				sa(t_stack **stack_a, t_bench *bench);
void				sb(t_stack **stack_b, t_bench *bench);
void				ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void				pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void				pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
int					check_if_sorted(t_stack *stack);
void				sort_4_nb(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);
int					get_max(t_stack *stack);
int					ft_verify_isdigit(char *str);
void				init_count(t_bench *bench);
int					main(int argc, char **argv);
void				free_stack(t_stack **stack);
void				stack_init(t_stack **stack_a, char *argv, char **str);
void				simple_algo(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);
void				sort_3_nb(t_stack **stack_a, t_bench *bench);
long long			is_atoi(const char *p);
int					ft_stack_size(t_stack *stack);
void				radix_sort(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);
char				*adaptive_str(t_stack **stack_a, t_stack **stack_b,
						double disorder, t_bench *bench);
int					check_dup(t_stack *stack, int nb);
void				putnbr_stderr(int nb);
void				set_condition(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);
void				print_bench(char *alg, t_bench *bench, char *type,
						float disorder);
void				put_float(float n);
double				count_disorder(t_stack *stack_a);
void				get_bench(t_stack **stack_a, t_stack **stack_b, t_flag *s);
void				medium_algo(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);
void				ft_put_index(t_stack *stack);
char				**ft_split(const char *s, char c);
t_stack				*parsing(int ac, char **av, int *algo, int *mode);
int					ft_strcmp(char *s1, char *s2);
int					is_flag(char *flag);
void				sort_5_nb(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);

#endif
