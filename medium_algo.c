/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:21:44 by loandria          #+#    #+#             */
/*   Updated: 2026/04/21 23:45:52 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	size;
	int	chunk_size;
	int	start;
	int	end;

	size = ft_stack_size(*stack_a);
	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	start = 0;
	end = chunk_size - 1;
	while (*stack_a)
	{
		if ((*stack_a)->index <= end)
		{
			pb(stack_a, stack_b, bench);
			if ((*stack_b)->index <= start)
				rb(stack_b, bench);
			start++;
			end++;
		}
		else
			ra(stack_a, bench);
	}
}

static void	put_max_to_top(t_stack **stack_b, t_bench *bench)
{
	int		max;
	int		pos;
	int		size;
	t_stack	*tmp;

	size = ft_stack_size(*stack_b);
	max = get_max(*stack_b);
	pos = 0;
	tmp = *stack_b;
	while (tmp && tmp->index != max)
	{
		tmp = tmp->nxt;
		pos++;
	}
	if (pos <= size / 2)
	{
		while ((*stack_b)->index != max)
			rb(stack_b, bench);
	}
	else
	{
		while ((*stack_b)->index != max)
			rrb(stack_b, bench);
	}
}

static void	push_b_to_a(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	while (*stack_b)
	{
		put_max_to_top(stack_b, bench);
		pa(stack_a, stack_b, bench);
	}
}

void	medium_algo(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (ft_stack_size(*stack_a) <= 5)
	{
		set_condition(stack_a, stack_b, bench);
		return ;
	}
	push_to_b(stack_a, stack_b, bench);
	push_b_to_a(stack_a, stack_b, bench);
}
