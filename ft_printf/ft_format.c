/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:36:11 by tojorana          #+#    #+#             */
/*   Updated: 2026/04/23 14:37:52 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ar, const char c, int fd)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ar, int), fd));
	if (c == 's')
		return (ft_putstr(va_arg(ar, char *), fd));
	if (c == 'p')
		return (ft_putptr(va_arg(ar, void *), fd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ar, int), fd));
	if (c == 'u')
		return (ft_putunsigned(va_arg(ar, unsigned int), fd));
	if (c == 'x')
		return (ft_puthexlower(va_arg(ar, unsigned int), c, fd));
	if (c == 'X')
		return (ft_puthexupper(va_arg(ar, unsigned int), c, fd));
	if (c == '%')
		return (ft_putchar('%', fd));
	return (0);
}
