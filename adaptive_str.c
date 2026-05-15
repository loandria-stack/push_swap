/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tojorana <tojorana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 01:03:17 by loandria          #+#    #+#             */
/*   Updated: 2026/04/23 11:55:17 by tojorana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*adaptive_str(t_stack **stack_a, t_stack **stack_b, double disorder,
		t_bench *bench)
{
	if (disorder < 0.2)
	{
		simple_algo(stack_a, stack_b, bench);
		return ("O(n2)");
	}
	else if (disorder < 0.5)
	{
		medium_algo(stack_a, stack_b, bench);
		return ("O(n√n) ");
	}
	else
	{
		radix_sort(stack_a, stack_b, bench);
		return ("O(nlogn)");
	}
}
