/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:30:25 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/07 09:44:33 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	virfy2(t_game *game, int key, int y, int i)
{
	if ((key == 13 || key == 126) && game->map[y][i] == 'P' &&
		check_direction(game, game->map[y - 1][i]))
	{
		do_move_w(game, i, y);
		print_move(game, key);
		return (0);
	}
	if ((key == 2 || key == 124) && game->map[y][i] == 'P' &&
		check_direction(game, game->map[y][i + 1]))
	{
		do_move_d(game, i, y);
		print_move(game, key);
		return (0);
	}
	return (1);
}

int	virfy(t_game *game, int key, int y, int i)
{
	int	check;

	check = 0;
	if (!virfy2(game, key, y, i))
		return (0);
	if ((key == 1 || key == 125) && game->map[y][i] == 'P' &&
		check_direction(game, game->map[y + 1][i]))
	{
		do_move_s(game, i, y, &check);
		print_move(game, key);
		return (check);
	}
	if ((key == 0 || key == 123) && game->map[y][i] == 'P' &&
		check_direction(game, game->map[y][i - 1]))
	{
		do_move_a(game, i, y);
		print_move(game, key);
		return (0);
	}
	return (2);
}

static void	find_p_e_c(char *str, int *p, int *e, int *c)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == 'E')
			(*e)++;
		else if (str[j] == 'P')
			(*p)++;
		else if (str[j] == 'C')
			(*c)++;
		j++;
	}
}

static void	find_p_position(char *str, int i, t_game **game)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == 'P')
		{
			(*game)->player_pos.x = i;
			(*game)->player_pos.y = j;
		}
		if (str[j] == 'N')
		{
			(*game)->monster_pos.x = i;
			(*game)->monster_pos.y = j;
			(*game)->n_monsters++;
		}
		j++;
	}
}

void	exit_and_player(char **map, t_game **game)
{
	int	i;
	int	e;
	int	p;
	int	c;

	i = 0;
	e = 0;
	p = 0;
	c = 0;
	(*game)->n_monsters = 0;
	while (map[++i])
	{
		find_p_e_c(map[i], &p, &e, &c);
		find_p_position(map[i], i, game);
	}
	if (p != 1 || e != 1 || c == 0)
	{
		free_map(map);
		error('m');
	}
	if ((*game)->n_monsters < 1)
	{
		free_map(map);
		error('m');
	}
}
