/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 05:50:11 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/03 22:55:08 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	org_monster_move(t_game *ptr, int mon_move)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			if (ptr->map[i][j] == 'N' && mon_move > 0)
			{
				move(ptr, i, j);
				mon_move--;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	move(t_game *ptr, int i, int y)
{
	int	oldi;
	int	oldj;
	int	check;

	oldi = i;
	oldj = y;
	check = 8;
	get_monster_move(ptr, &i, &y);
	check = 1;
	if (ptr->map[i][y] == '0' && check == 1)
	{
		ptr->map[oldi][oldj] = ptr->map[i][y];
		ptr->map[i][y] = 'N';
	}
	else if (ptr->map[i][y] == 'P')
	{
		drow(ptr);
		error('e');
	}
}
