/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 08:14:31 by tojorana          #+#    #+#             */
/*   Updated: 2026/04/23 14:38:22 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, fmt);
	i = 0;
	count = 0;
	if (fmt == NULL)
		return (-1);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i])
				count += ft_format(args, fmt[i], 1);
		}
		else
			count += write(1, &fmt[i], 1);
		if (fmt[i])
			i++;
	}
	va_end(args);
	return (count);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, fmt);
	i = 0;
	count = 0;
	if (fmt == NULL)
		return (-1);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i])
				count += ft_format(args, fmt[i], fd);
		}
		else
			count += write(fd, &fmt[i], 1);
		if (fmt[i])
			i++;
	}
	va_end(args);
	return (count);
}
