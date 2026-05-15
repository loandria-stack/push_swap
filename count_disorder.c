/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 09:24:42 by loandria          #+#    #+#             */
/*   Updated: 2026/04/20 11:33:24 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	count_disorder(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;
	int		total_pairs;
	int		mistakes;

	total_pairs = 0;
	mistakes = 0;
	i = stack_a;
	while (i)
	{
		j = i->nxt;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->nxt;
		}
		i = i->nxt;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
