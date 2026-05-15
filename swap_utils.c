/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:03:06 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 06:29:29 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verify_isdigit(char *str)
{
	int		i;
	long	nb;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	nb = is_atoi(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

int	check_dup(t_stack *stack, int nb)
{
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == nb)
			return (1);
		tmp = tmp->nxt;
	}
	return (0);
}

int	check_if_sorted(t_stack *stack)
{
	if (!stack || !stack->nxt)
		return (1);
	while (stack->nxt)
	{
		if (stack->value > stack->nxt->value)
			return (0);
		stack = stack->nxt;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack != NULL)
	{
		temp = (*stack)->nxt;
		free(*stack);
		*stack = temp;
	}
}
