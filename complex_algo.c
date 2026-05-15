/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:38:44 by loandria          #+#    #+#             */
/*   Updated: 2026/04/21 23:39:20 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack_a)
{
	int	max;
	int	bits;

	max = get_max(stack_a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_pass(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	bits;
	int	i;
	int	j;
	int	size;

	bits = get_max_bits(*stack_a);
	size = ft_stack_size(*stack_a);
	i = 0;
	j = 0;
	while (i < bits)
	{
		size = ft_stack_size(*stack_a);
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b, bench);
			else
				ra(stack_a, bench);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, bench);
		i++;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (ft_stack_size(*stack_a) <= 5)
	{
		set_condition(stack_a, stack_b, bench);
		return ;
	}
	radix_pass(stack_a, stack_b, bench);
}
