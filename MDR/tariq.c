/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tariq.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 05:14:20 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/03 21:13:14 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	map_len(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

static int	map_x(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	floodfill2(char **str, int x, int y, t_game **player)
{
	if (!str || !player || !*player)
		return (0);
	if (x < 0 || x > map_x(str) || y < 0 || y > map_len(str))
		return (0);
	if (str[x][y] == '1' || str[x][y] == 'Z')
		return (0);
	if (str[x][y] == 'C')
		(*player)->m_coine++;
	if (str[x][y] == 'E')
	{
		if ((*player)->n_door == 0)
			(*player)->n_door++;
		return (0);
	}
	str[x][y] = 'Z';
	floodfill2(str, x + 1, y, player);
	floodfill2(str, x, y + 1, player);
	floodfill2(str, x - 1, y, player);
	floodfill2(str, x, y - 1, player);
	return ((*player)->m_coine);
}

char	**copy_map(char **map, int rows)
{
	int		i;
	char	**copy;

	i = 0;
	copy = ft_malloc (sizeof(char *) * rows + 1);
	if (!copy)
		ft_exit(1);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	floodfill(char **map, int x, int y, t_game **player)
{
	char	**str;
	int		res;
	int		i;

	str = copy_map(map, map_x(map));
	(*player)->m_coine = 0;
	(*player)->n_door = 0;
	res = floodfill2(str, x, y, player);
	if ((*player)->n_door != 1)
		error('m');
	i = 0;
	while (i < map_x(map))
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (res);
}
