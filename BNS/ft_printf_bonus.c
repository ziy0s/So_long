/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:41:37 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/06 15:57:23 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put(char s, va_list args)
{
	int	res;

	res = 0;
	if (s == 'd' || s == 'i')
		res += ft_putnbr_fd(va_arg(args, int), 1);
	else if (s == 'c')
		res += ft_putchar_fd(va_arg(args, int), 1);
	else if (s == 's')
		res += ft_putstr_fd(va_arg(args, char *), 1);
	else if (s == 'p')
		res += ft_puthex(va_arg(args, size_t), "0123456789abcdef", s);
	else if (s == 'x')
		res += ft_puthex(va_arg(args, unsigned int), "0123456789abcdef", s);
	else if (s == 'u')
		res += ft_putu(va_arg(args, unsigned int));
	else if (s == 'X')
		res += ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF", s);
	else if (s == '%')
		res += ft_putchar_fd('%', 1);
	else
		res += ft_putchar_fd(s, 1);
	return (res);
}

static int	ft_check(const char *str, va_list args)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
			{
				res += ft_put(str[i + 1], args);
				i++;
			}
		}
		else
			res += ft_putchar_fd(str[i], 1);
		i++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	res = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, format);
	res = ft_check(format, args);
	va_end(args);
	return (res);
}
