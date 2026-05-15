/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:53:43 by loandria          #+#    #+#             */
/*   Updated: 2026/04/20 09:54:04 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_copy_tab(t_stack *a, int size)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	tmp = a;
	while (i < size)
	{
		tab[i] = tmp->value;
		i++;
		tmp = tmp->nxt;
	}
	return (tab);
}

static void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

static int	ft_find_index(int *tab, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_put_index(t_stack *stack)
{
	int		size;
	int		*tab;
	t_stack	*tmp;

	size = ft_stack_size(stack);
	tab = ft_copy_tab(stack, size);
	if (!tab)
		return ;
	ft_sort_tab(tab, size);
	tmp = stack;
	while (tmp)
	{
		tmp->index = ft_find_index(tab, size, tmp->value);
		tmp = tmp->nxt;
	}
	free(tab);
}
