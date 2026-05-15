/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:36:20 by tojorana          #+#    #+#             */
/*   Updated: 2026/04/23 14:38:06 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexupper(unsigned int hupp, char f, int fd)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (hupp >= 16)
		count += ft_puthexupper((unsigned long)hupp / 16, f, fd);
	count += ft_putchar(hex[(unsigned long)hupp % 16], fd);
	return (count);
}

int	ft_puthexlower(unsigned int hlow, char f, int fd)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (hlow >= 16)
		count += ft_puthexlower((unsigned long)hlow / 16, f, fd);
	count += ft_putchar(hex[(unsigned long)hlow % 16], fd);
	return (count);
}
