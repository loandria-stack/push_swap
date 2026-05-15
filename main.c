/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 23:29:01 by loandria          #+#    #+#             */
/*   Updated: 2026/04/21 21:38:05 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	swap_tools(int ac, char **av, int *algo, int *mode)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_flag	s;
	char	**str;

	(void)ac;
	str = av;
	stack_a = NULL;
	stack_b = NULL;
	init_count(&s.bench);
	stack_a = parsing(ac, str, algo, mode);
	s.algo = *algo;
	s.mode = *mode;
	s.algo_name = NULL;
	s.complx = NULL;
	ft_put_index(stack_a);
	get_bench(&stack_a, &stack_b, &s);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_bench	bench;
	int		algo;
	int		mode;
	int		result;

	init_count(&bench);
	algo = 0;
	mode = 0;
	if (argc < 2)
		return (0);
	argv += 1;
	argc -= 1;
	result = swap_tools(argc, argv, &algo, &mode);
	return (result);
}
