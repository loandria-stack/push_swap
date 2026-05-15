/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 08:57:03 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 07:07:18 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_flag *s,
		t_bench *bench)
{
	if (check_if_sorted(*stack_a))
		return ;
	else if (s->algo == 1)
		simple_algo(stack_a, stack_b, bench);
	else if (s->algo == 2)
		medium_algo(stack_a, stack_b, bench);
	else if (s->algo == 3)
		radix_sort(stack_a, stack_b, bench);
	else if (s->algo == 4)
		adaptive_str(stack_a, stack_b, count_disorder(*stack_a), bench);
}

static char	*ft_adaptive_name(double dis)
{
	if (dis < 0.2)
		return ("O(n²)");
	else if (dis < 0.5)
		return ("O(n√n)");
	else
		return ("O(nlogn)");
}

static void	algo_set(double dis, t_flag *s)
{
	if (s->algo == 1)
	{
		s->algo_name = "simple";
		s->complx = "O(n²)";
	}
	else if (s->algo == 2)
	{
		s->algo_name = "medium";
		s->complx = "O(n√n)";
	}
	else if (s->algo == 3)
	{
		s->algo_name = "complex";
		s->complx = "O(nlogn)";
	}
	else if (s->algo == 4)
	{
		s->algo_name = "adaptive";
		s->complx = ft_adaptive_name(dis);
	}
}

void	get_bench(t_stack **stack_a, t_stack **stack_b, t_flag *s)
{
	double	disorder;

	s->bench.mode = &s->mode;
	disorder = count_disorder(*stack_a);
	if (s->algo == 0)
	{
		s->algo = 4;
	}
	algo_set(disorder, s);
	sort_stack(stack_a, stack_b, s, &s->bench);
	if (s->mode == 1)
		print_bench(s->complx, &s->bench, s->algo_name, (float)disorder);
}

int	is_flag(char *flag)
{
	if (!ft_strcmp(flag, "--simple") || !ft_strcmp(flag, "--medium")
		|| !ft_strcmp(flag, "--complex") || !ft_strcmp(flag, "--adaptive")
		|| !ft_strcmp(flag, "--bench"))
		return (1);
	return (0);
}
