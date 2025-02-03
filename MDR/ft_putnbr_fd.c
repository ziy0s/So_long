/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:59:32 by zaissi            #+#    #+#             */
/*   Updated: 2025/01/24 19:21:48 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	nbr;
	int		res;

	res = 0;
	if (fd < 0)
		return (-1);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		res++;
	}
	if (n > 9)
		res += ft_putnbr_fd(n / 10, fd);
	nbr = n % 10 + 48;
	res++;
	write(fd, &nbr, 1);
	return (res);
}
