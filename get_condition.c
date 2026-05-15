/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 23:40:00 by loandria          #+#    #+#             */
/*   Updated: 2026/04/21 23:40:23 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_condition(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (ft_stack_size(*stack_a) == 2)
	{
		sa(stack_a, bench);
		return ;
	}
	if (ft_stack_size(*stack_a) == 3)
	{
		sort_3_nb(stack_a, bench);
		return ;
	}
	if (ft_stack_size(*stack_a) == 4)
	{
		sort_4_nb(stack_a, stack_b, bench);
		return ;
	}
	if (ft_stack_size(*stack_a) == 5)
	{
		sort_5_nb(stack_a, stack_b, bench);
		return ;
	}
}
