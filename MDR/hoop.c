/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hoop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 04:20:54 by zaissi            #+#    #+#             */
/*   Updated: 2025/01/27 02:32:13 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	tatima(t_game *ptr)
{
	drow(ptr);
	mlx_key_hook(ptr->win_ptr, key_hook, ptr);
	mlx_hook(ptr->win_ptr, 17, 0, clean_exit, ptr);
	mlx_loop(ptr->mlx_ptr);
}

int	clean_exit(t_game *game)
{
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
		i++;
	}
	i--;
	is_valid_wall2(i, str);
}

void	creat_stract(t_game *ptr)
{
	int	cond;

	cond = 32;
	ptr->mlx_ptr = mlx_init();
	if (!ptr->mlx_ptr)
		error('m');
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->win_width * 32,
			ptr->win_hight * 32, "So Long 42 Game");
	if (!ptr->win_ptr)
		error('m');
	ptr->soil = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/soil.xpm", &cond, &cond);
	ptr->wall = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/lava.xpm", &cond, &cond);
	ptr->mony = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/wallet.xpm", &cond, &cond);
	ptr->door = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/door.xpm", &cond, &cond);
	ptr->player = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"./textures/back.xpm", &cond, &cond);
	if (!ptr->player || !ptr->soil || !ptr->wall || !ptr->mony || !ptr->door)
		error('m');
}
