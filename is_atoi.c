/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tojorana <tojorana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 08:34:50 by loandria          #+#    #+#             */
/*   Updated: 2026/04/22 09:39:52 by tojorana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	is_atoi(const char *p)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((p[i] >= 9 && p[i] <= 13) || p[i] == 32)
		i++;
	if (p[i] == '+' || p[i] == '-')
	{
		if (p[i] == '-')
			sign *= -1;
		i++;
	}
	while (p[i] >= '0' && p[i] <= '9')
	{
		nb = nb * 10 + (p[i] - '0');
		i++;
	}
	return (nb * sign);
}
