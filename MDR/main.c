/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:30:21 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/04 00:52:06 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char str)
{
	if (str == 'm')
		write(2, "Error\nInvailed map !!\n", 22);
	ft_exit(1);
}

int	n_coines(char **map)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

int	check_direction(t_game *game, char s2)
{
	return (s2 == '0' || s2 == 'C' || (s2 == 'E' && !n_coines(game->map)));
}

int	key_hook(int key, t_game *game)
{
	int	i;
	int	y;
	int	check;

	y = 0;
	if (key == 53)
		clean_exit(game);
	while (game->map[y])
	{
		i = 0;
		while (game->map[y][i])
		{
			check = virfy(game, key, y, i);
			if (check != 2)
				break ;
			i++;
		}
		if (check == 1)
			break ;
		y++;
	}
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	drow(game);
	return (0);
}

// void f()
// {
// 	system("leaks so_long");
// }

int	main(int c, char *v[])
{
	t_game	*ptr;
	int		cond;

	// atexit(f);
	if (c != 2)
		exit(1);
	cond = 32;
	ptr = ft_malloc(sizeof(t_game));
	if (!ptr)
		ft_exit(1);
	ptr->map = get_map(v[1], ptr);
	if (!ptr->map)
		error('m');
	creat_stract(ptr);
	ptr->p_move = 0;
	tatima(ptr);
}
