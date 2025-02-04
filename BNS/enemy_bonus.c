/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:58:54 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/03 22:56:59 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy(char **str)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N')
				e++;
			j++;
		}
		i++;
	}
	if (e == 0)
		error('m');
}

char	*put_str(t_game *ptr)
{
	char	*str;
	int		i;
	int		buck;

	i = 0;
	buck = ptr->p_move;
	while (buck)
	{
		i++;
		buck /= 10;
	}
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		error('m');
	buck = ptr->p_move;
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = buck % 10 + '0';
		buck = buck / 10;
		i--;
	}
	return (str);
}

int	x_position(t_game *ptr, int i, int y)
{
	int	tmp;

	tmp = i;
	while (ptr->map[tmp][y])
	{
		if (ptr->map[tmp][y] == 'P')
			return (1);
		if (ptr->map[tmp][y] == '1' && tmp < ptr->win_hight)
			break ;
		tmp++;
	}
	tmp = i;
	while (ptr->map[tmp][y])
	{
		if (ptr->map[tmp][y] == 'P')
			return (1);
		if (ptr->map[tmp][y] == '1' && tmp < ptr->win_hight)
			break ;
		tmp--;
	}
	return (0);
}

int	y_position(t_game *ptr, int i, int y)
{
	int	tmp;

	tmp = y;
	while (ptr->map[i][tmp])
	{
		if (ptr->map[i][tmp] == 'P')
			return (1);
		if (ptr->map[i][tmp] == '1')
			break ;
		tmp++;
	}
	tmp = y;
	while (ptr->map[i][tmp])
	{
		if (ptr->map[i][tmp] == 'P')
			return (1);
		if (ptr->map[i][tmp] == '1')
			break ;
		tmp--;
	}
	return (0);
}

static void	if_is_wall(t_game *ptr, int *i, int *y)
{
	drow(ptr);
	if (ptr->map[*i][*y] == '1')
	{
		if (ptr->player_pos.x > *i)
			(*i)++;
		if (ptr->player_pos.y > *y)
			(*y)++;
		if (ptr->player_pos.x < *i)
			(*i)--;
		if (ptr->player_pos.y < *y)
			(*y)--;
	}
	drow(ptr);
}

void	get_monster_move(t_game *ptr, int *i, int *y)
{
	int oldi;
	int oldy;
	
	oldi = *i;
	oldy = *y;
	if (ptr->player_pos.x > *i)
		(*i)++;
	if (ptr->player_pos.y > *y)
		(*y)++;
	if (ptr->player_pos.x < *i)
		(*i)--;
	if (ptr->player_pos.y < *y)
		(*y)--;
	if (ptr->map[*i][*y] != '0')
		if_is_wall(ptr, i, y);
}
