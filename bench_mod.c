/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 08:15:10 by loandria          #+#    #+#             */
/*   Updated: 2026/04/23 14:41:55 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

static void	display_strategy(char *type, char *alg)
{
	ft_dprintf(2, "[bench] strategy: %s / %s\n", type, alg);
}

static void	display_disorder(float dis)
{
	ft_dprintf(2, "[bench] disorder: ");
	put_float(dis * 100.0f);
	ft_dprintf(2, "%%\n");
}

static void	op_bench(t_bench *bench)
{
	ft_dprintf(2, "[bench] total_ops: ");
	ft_dprintf(2, "%d\n", bench->total_ops);
	ft_dprintf(2, "[bench] ");
	ft_dprintf(2, "sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->sa, bench->sb,
		bench->ss, bench->pa, bench->pb);
	ft_dprintf(2, "[bench] ");
	ft_dprintf(2, "ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", bench->ra,
		bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}

void	print_bench(char *alg, t_bench *bench, char *type, float disorder)
{
	display_disorder(disorder);
	display_strategy(type, alg);
	op_bench(bench);
}
