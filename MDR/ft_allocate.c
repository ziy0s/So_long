/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:02:16 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/03 21:21:47 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_free(void *ptr, int flag)
{
	static void	*lst[INT_MAX];
	static int	i;
	int			j;
	
	if (flag || flag == 0)
	{
		j = 0;
		while (lst[j])
		{
			free (lst[j]);
			j++;
		}
	}
	else
		lst[i++] = ptr;
}

void	ft_exit(int i)
{
	ft_free(NULL, i);
	if (i)
		ft_putstr_fd("ERROR\n", 2);
	exit(i);
}

void    *ft_malloc(size_t size)
{
	void    *ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_exit(1);
	ft_free(ptr, 2);
	return (ptr);
}
