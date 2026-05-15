/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tojorana <tojorana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 01:26:14 by loandria          #+#    #+#             */
/*   Updated: 2026/04/23 11:22:38 by tojorana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_nb(t_stack **stack_a, t_bench *bench)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->nxt->value;
	c = (*stack_a)->nxt->nxt->value;
	if (a > b && b < c && a < c)
		sa(stack_a, bench);
	else if (a > b && b > c)
	{
		sa(stack_a, bench);
		rra(stack_a, bench);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, bench);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, bench);
		ra(stack_a, bench);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, bench);
}
