/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:58:00 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 07:10:17 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = (*src)->nxt;
	tmp->nxt = *dst;
	*dst = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	if (bench)
	{
		bench->pa++;
		bench->total_ops++;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	if (bench)
	{
		bench->pb++;
		bench->total_ops++;
	}
}
