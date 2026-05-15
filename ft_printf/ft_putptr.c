/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 23:49:35 by tojorana          #+#    #+#             */
/*   Updated: 2026/04/23 14:38:07 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexalowercase(unsigned long low, int fd)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (low >= 16)
		count += ft_puthexalowercase(low / 16, fd);
	count += ft_putchar(hex[low % 16], fd);
	return (count);
}

int	ft_putptr(void *p, int fd)
{
	int				count;
	unsigned long	addr;

	count = 0;
	addr = (unsigned long)p;
	if (!p)
		return (write(fd, "(nil)", 5));
	count = write(fd, "0x", 2);
	count += ft_puthexalowercase(addr, fd);
	return (count);
}
