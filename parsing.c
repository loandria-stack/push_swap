/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:17:19 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 07:07:39 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	apply_algo(int *algo, int num_algo)
{
	*algo = num_algo;
	return (1);
}

static void	free_str_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	check_flags(char **av, int *algo, int *mode)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "--simple") == 0)
			apply_algo(algo, 1);
		else if (ft_strcmp(av[i], "--medium") == 0)
			apply_algo(algo, 2);
		else if (ft_strcmp(av[i], "--complex") == 0)
			apply_algo(algo, 3);
		else if (ft_strcmp(av[i], "--adaptive") == 0)
			apply_algo(algo, 4);
		else if (ft_strcmp(av[i], "--bench") == 0)
			*mode = 1;
		i++;
	}
}

static void	pars_arg(char **av, t_stack **stack_a, char **str)
{
	int	i;

	i = 0;
	while (av[i])
	{
		stack_init(stack_a, av[i], str);
		i++;
	}
}

t_stack	*parsing(int ac, char **av, int *algo, int *mode)
{
	char	**str;
	int		i;
	t_stack	*a;

	a = NULL;
	i = 0;
	while (i < ac)
	{
		str = ft_split(av[i], ' ');
		if (!str)
			return (NULL);
		check_flags(str, algo, mode);
		pars_arg(str, &a, str);
		free_str_tab(str);
		i++;
	}
	return (a);
}
