/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:33:19 by zaissi            #+#    #+#             */
/*   Updated: 2025/01/24 19:22:02 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putu(unsigned int i)
{
	int	res;

	res = 0;
	if (i > 9)
	{
		res += ft_putu(i / 10);
		res += ft_putu(i % 10);
	}
	else
		res += ft_putnbr_fd(i, 1);
	return (res);
}
