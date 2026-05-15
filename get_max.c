/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:21:54 by loandria          #+#    #+#             */
/*   Updated: 2026/04/20 12:22:18 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	if (!stack)
		return (0);
	max = stack->index;
	tmp = stack->nxt;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->nxt;
	}
	return (max);
}
