/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:36:30 by loandria          #+#    #+#             */
/*   Updated: 2026/04/21 16:06:09 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_nb(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	while (ft_stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b, bench);
		else
			ra(stack_a, bench);
	}
	sort_3_nb(stack_a, bench);
	if ((*stack_b)->index == 0)
	{
		sb(stack_b, bench);
	}
	pa(stack_a, stack_b, bench);
	pa(stack_a, stack_b, bench);
}
