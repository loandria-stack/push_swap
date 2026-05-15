/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tojorana <tojorana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:40:06 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 09:39:47 by tojorana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display_error(t_stack **stack_a, char **str)
{
	int	i;

	write(2, "Error\n", 6);
	free_stack(stack_a);
	if (str)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	exit(1);
}

static int	add_back(t_stack **stack_a, int nb)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = nb;
	new->nxt = NULL;
	if (*stack_a)
	{
		tmp = *stack_a;
		while (tmp->nxt)
			tmp = tmp->nxt;
		tmp->nxt = new;
	}
	else
		*stack_a = new;
	return (1);
}

void	stack_init(t_stack **stack_a, char *argv, char **str)
{
	long long	nb;

	if (is_flag(argv))
		return ;
	nb = is_atoi(argv);
	if (!ft_verify_isdigit(argv) || check_dup(*stack_a, nb))
		display_error(stack_a, str);
	if (!add_back(stack_a, nb))
		display_error(stack_a, str);
}
