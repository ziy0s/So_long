/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hoop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 04:20:54 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/03 05:54:35 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	monster_move(t_game *ptr)
{
	int	mon_move;

	ptr->frame_counter++;
	if (ptr->frame_counter < 800)
		return (0);
	ptr->frame_counter = 0;
	mon_move = ptr->n_monsters;
	org_monster_move(ptr, mon_move);
	drow(ptr);
	return (0);
}

void	tatima(t_game *ptr)
{
	drow(ptr);
	mlx_loop_hook(ptr->mlx_ptr, monster_move, ptr);
	mlx_key_hook(ptr->win_ptr, key_hook, ptr);
	mlx_hook(ptr->win_ptr, 17, 0, clean_exit, ptr);
	mlx_loop(ptr->mlx_ptr);
}

int	clean_exit(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->enemy);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

static void	is_valid_wall2(int i, char **str)
{
	int	j;

	j = 0;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			error('m');
		j++;
	}
	j = 0;
	while (str[0][j])
	{
		if (str[0][j] != '1' && str[0][j] != '\n')
			error('m');
		j++;
	}
}

void	is_valid_wall(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (i > 0 && str[i + 1] && str[i][j])
		{
			if (str[i][j] != '1' && str[i][j] != '\n')
				break ;
			j++;
		}
		if (!str[i][j])
			error('m');
		i++;
	}
	i--;
	is_valid_wall2(i, str);
}
