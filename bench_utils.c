/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 23:58:20 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 06:27:53 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_count(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total_ops = 0;
}

void	putnbr_stderr(int nb)
{
	int		i;
	char	str[20];

	i = 0;
	if (nb == 0)
	{
		write(2, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(2, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i] = (char)(nb % 10 + '0');
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		write(2, &str[i - 1], 1);
		i--;
	}
}

void	put_float(float n)
{
	int	dec;
	int	ent;

	n += 0.005f;
	ent = (int)n;
	dec = (int)((n - ent) * 100.0f);
	if (dec >= 100)
	{
		ent++;
		dec = 0;
	}
	putnbr_stderr(ent);
	write(2, ".", 1);
	if (dec < 10)
		write(2, "0", 1);
	putnbr_stderr(dec);
}
