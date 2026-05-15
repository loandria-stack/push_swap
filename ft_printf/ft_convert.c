/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:36:28 by tojorana          #+#    #+#             */
/*   Updated: 2026/04/23 14:37:50 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int fd)
{
	int	res;

	res = write(fd, &c, 1);
	return (res);
}

int	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (str[i])
		i++;
	write(fd, str, i);
	return (i);
}

int	ft_putnbr(int nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (nbr < 0)
	{
		count += write(fd, "-", 1);
		count += ft_putnbr(-nbr, fd);
	}
	else if (nbr < 10)
	{
		count += ft_putchar(nbr + '0', fd);
	}
	else
	{
		count += ft_putnbr(nbr / 10, fd);
		count += ft_putnbr(nbr % 10, fd);
	}
	return (count);
}

int	ft_putunsigned(unsigned int u, int fd)
{
	int	count;

	count = 0;
	if (u >= 10)
		count += ft_putunsigned(u / 10, fd);
	count += ft_putchar((u % 10) + '0', fd);
	return (count);
}
