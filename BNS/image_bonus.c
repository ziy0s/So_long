/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 04:44:14 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/07 09:39:00 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_image(t_game *game, char str, int j, int i)
{
	if (str == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall, j * 32, i * 32);
	else if (str == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->mony, j * 32, i * 32);
	}
	else if (str == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->door, j * 32, i * 32);
	else if (str == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player, j * 32, i * 32);
		game->player_pos.x = i;
		game->player_pos.y = j;
	}
	else if (str == 'N')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->enemy, j * 32, i * 32);
}

void	drow(t_game *game)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = put_str(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->soil, j * 32, i * 32);
			put_image(game, game->map[i][j], j, i);
			j++;
		}
		i++;
	}
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 5, 0x000000000, "Moves :");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 85, 5, 0x000000000, str);
}

void	creat_images(t_game *ptr)
{
	int	size;

	size = 32;
	ptr->soil = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/soil.xpm", &size, &size);
	ptr->wall = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/lava.xpm", &size, &size);
	ptr->mony = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/wallet.xpm", &size, &size);
	ptr->door = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/door.xpm", &size, &size);
	ptr->player = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/back.xpm", &size, &size);
	ptr->enemy = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/zombie1.xpm", &size, &size);
	if (!ptr->player || !ptr->soil || !ptr->wall || !ptr->mony || !ptr->door)
		error('m');
	if (!ptr->enemy)
		error('m');
}
