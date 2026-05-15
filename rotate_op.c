/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:00:45 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 07:09:32 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->nxt)
		return ;
	temp = *stack;
	*stack = (*stack)->nxt;
	temp->nxt = NULL;
	last = *stack;
	while (last->nxt != NULL)
	{
		last = last->nxt;
	}
	last->nxt = temp;
}

void	ra(t_stack **stack_a, t_bench *bench)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	if (bench)
	{
		bench->ra++;
		bench->total_ops++;
	}
}

void	rb(t_stack **stack_b, t_bench *bench)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	if (bench)
	{
		bench->rb++;
		bench->total_ops++;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	if (bench)
	{
		bench->rr++;
		bench->total_ops++;
	}
}
