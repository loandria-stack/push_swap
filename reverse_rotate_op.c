/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:02:27 by loandria          #+#    #+#             */
/*   Updated: 2026/04/23 10:31:18 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->nxt)
		return ;
	temp = *stack;
	while (temp->nxt->nxt != NULL)
		temp = temp->nxt;
	last = temp->nxt;
	temp->nxt = NULL;
	last->nxt = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a, t_bench *bench)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	if (bench)
	{
		bench->rra++;
		bench->total_ops++;
	}
}

void	rrb(t_stack **stack_b, t_bench *bench)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	if (bench)
	{
		bench->rrb++;
		bench->total_ops++;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	if (bench)
	{
		bench->rrr++;
		bench->total_ops++;
	}
}
