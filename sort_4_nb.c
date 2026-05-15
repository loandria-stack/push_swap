/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:42:13 by loandria          #+#    #+#             */
/*   Updated: 2026/04/21 21:43:47 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->nxt;
	}
	return (min);
}

void	sort_4_nb(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	min_index;

	min_index = get_min(*stack_a);
	while ((*stack_a)->index != min_index)
		ra(stack_a, bench);
	pb(stack_a, stack_b, bench);
	sort_3_nb(stack_a, bench);
	pa(stack_a, stack_b, bench);
}
