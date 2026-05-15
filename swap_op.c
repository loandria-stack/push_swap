/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:11:20 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 07:08:55 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->nxt)
		return ;
	temp = (*stack)->nxt;
	(*stack)->nxt = temp->nxt;
	temp->nxt = *stack;
	*stack = temp;
}

void	sa(t_stack **stack_a, t_bench *bench)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	if (bench)
	{
		bench->sa++;
		bench->total_ops++;
	}
}

void	sb(t_stack **stack_b, t_bench *bench)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	if (bench)
	{
		bench->sb++;
		bench->total_ops++;
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	if (bench)
	{
		bench->ss++;
		bench->total_ops++;
	}
}
