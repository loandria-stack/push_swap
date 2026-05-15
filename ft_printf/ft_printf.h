/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandria <loandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:36:57 by tojorana          #+#    #+#             */
/*   Updated: 2026/04/23 14:38:00 by loandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_putnbr(int nbr, int fd);
int	ft_putunsigned(unsigned int u, int fd);
int	ft_puthexupper(unsigned int hupp, char f, int fd);
int	ft_puthexlower(unsigned int hlow, char f, int fd);
int	ft_putptr(void *p, int fd);
int	ft_format(va_list ar, const char c, int fd);
int	ft_printf(const char *fmt, ...);
int	ft_dprintf(int fd, const char *fmt, ...);

#endif
