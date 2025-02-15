/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 04:44:14 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/06 15:29:44 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	put_image(t_game *game, char str, int j, int i)
{
	int	n;

	n = 0;
	if (str == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall, j * 32, i * 32);
	else if (str == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->mony, j * 32, i * 32);
		n++;
	}
	else if (str == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->door, j * 32, i * 32);
	else if (str == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player, j * 32, i * 32);
	return (n);
}

void	drow(t_game *game)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->soil, j * 32, i * 32);
			n += put_image(game, game->map[i][j], j, i);
			j++;
		}
		i++;
	}
}
