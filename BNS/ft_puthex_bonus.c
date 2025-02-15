/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:12:19 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/06 15:58:07 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_puthex(unsigned long n, char *str, int s)
{
	int		i;
	int		res;
	char	buff[17];

	i = 0;
	res = 0;
	if (n == 0 && s == 'p')
		return (ft_putstr_fd("0x0", 1));
	if (n == 0 && (s == 'x' || s == 'X'))
		return (ft_putchar_fd('0', 1));
	while (n > 0)
	{
		buff[i] = str[n % 16];
		n /= 16;
		i++;
	}
	if (s == 'p')
		res += ft_putstr_fd("0x", 1);
	while (i > 0)
	{
		res += ft_putchar_fd(buff[--i], 1);
	}
	return (res);
}

int	ft_puthex_x(unsigned int n, char *str, int s)
{
	int		i;
	int		res;
	char	buff[17];

	i = 0;
	res = 0;
	if (n == 0 && (s == 'x' || s == 'X'))
		return (ft_putchar_fd('0', 1));
	while (n > 0)
	{
		buff[i] = str[n % 16];
		n /= 16;
		i++;
	}
	while (i > 0)
	{
		res += ft_putchar_fd(buff[--i], 1);
	}
	return (res);
}
