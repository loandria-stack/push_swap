/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:51:09 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 00:55:40 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		min_val;
	int		min_pos;
	int		i;

	if (!stack)
		return (0);
	tmp = stack;
	min_val = tmp->value;
	min_pos = 0;
	i = 1;
	while (tmp->nxt != NULL)
	{
		tmp = tmp->nxt;
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

static void	put_min_to_top(t_stack **stack_a, t_bench *bench)
{
	int	rev_pos;
	int	min_pos;

	min_pos = get_min_pos(*stack_a);
	rev_pos = ft_stack_size(*stack_a) - min_pos;
	if (ft_stack_size(*stack_a) / 2 >= min_pos)
	{
		while (min_pos > 0)
		{
			ra(stack_a, bench);
			min_pos--;
		}
	}
	else
	{
		while (rev_pos > 0)
		{
			rra(stack_a, bench);
			rev_pos--;
		}
	}
}

void	simple_algo(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (check_if_sorted(*stack_a))
		return ;
	if (ft_stack_size(*stack_a) <= 5)
	{
		set_condition(stack_a, stack_b, bench);
		return ;
	}
	while (ft_stack_size(*stack_a))
	{
		put_min_to_top(stack_a, bench);
		if (check_if_sorted(*stack_a))
		{
			while (*stack_b)
				pa(stack_a, stack_b, bench);
			return ;
		}
		pb(stack_a, stack_b, bench);
	}
	sort_3_nb(stack_a, bench);
	while (*stack_b)
		pa(stack_a, stack_b, bench);
}
