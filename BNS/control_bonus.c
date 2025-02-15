/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 23:24:03 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/07 10:01:13 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	do_move_w(t_game *game, int i, int y)
{
	int	size;

	size = 32;
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/back.xpm", &size, &size);
	if (!game->player)
		ft_exit(1);
	if (game->map[y - 1][i] == 'N')
	{
		ft_printf("You lost in the game !!! :(\n");
		clean_exit(game);
	}
	if (game->map[y - 1][i] == 'E' && n_coines(game->map) == 0)
	{
		ft_printf("You Win in game !!!\n");
		clean_exit(game);
	}
	if (game->map[y - 1][i] == 'C' || (game->map[y - 1][i] == 'E'
			&& n_coines(game->map) != 0))
		game->map[y - 1][i] = '0';
	game->map[y][i] = '0';
	game->map[y - 1][i] = 'P';
	game->p_move++;
}

void	do_move_d(t_game *game, int i, int y)
{
	int	size;

	size = 32;
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/reght.xpm", &size, &size);
	if (!game->player)
		ft_exit(1);
	if (game->map[y][i + 1] == 'N')
	{
		ft_printf("You lost in the game !!! :(\n");
		clean_exit(game);
	}
	if (game->map[y][i + 1] == 'C' || (game->map[y][i + 1] == 'E'
			&& n_coines(game->map) != 0))
		game->map[y][i + 1] = '0';
	else if (game->map[y][i + 1] == 'E' && n_coines(game->map) == 0)
	{
		ft_printf("You Win in game !!!\n");
		clean_exit(game);
	}
	game->map[y][i] = '0';
	game->map[y][i + 1] = 'P';
	game->p_move++;
}

void	do_move_s(t_game *game, int i, int y, int *check)
{
	int	size;

	size = 32;
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/front.xpm", &size, &size);
	if (!game->player)
		ft_exit(1);
	if (game->map[y + 1][i] == 'N')
	{
		ft_printf("You lost in the game !!! :(\n");
		clean_exit(game);
	}
	if (game->map[y + 1][i] == 'C' || (game->map[y + 1][i] == 'E'
			&& n_coines(game->map) != 0))
		game->map[y + 1][i] = '0';
	else if (game->map[y + 1][i] == 'E' && n_coines(game->map) == 0)
	{
		ft_printf("You Win in game !!!\n");
		clean_exit(game);
	}
	game->map[y][i] = '0';
	game->map[y + 1][i] = 'P';
	*check = 1;
	game->p_move++;
}

void	do_move_a(t_game *game, int i, int y)
{
	int	size;

	size = 32;
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/left.xpm", &size, &size);
	if (!game->player)
		ft_exit(1);
	if (game->map[y][i - 1] == 'N')
	{
		ft_printf("You lost in the game !!! :(\n");
		clean_exit(game);
	}
	if (game->map[y][i - 1] == 'C' || (game->map[y][i - 1] == 'E'
			&& n_coines(game->map) != 0))
		game->map[y][i - 1] = '0';
	else if (game->map[y][i - 1] == 'E' && n_coines(game->map) == 0)
	{
		ft_printf("You Win in game !!!\n");
		clean_exit(game);
	}
	game->map[y][i] = '0';
	game->map[y][i - 1] = 'P';
	game->p_move++;
}

void	print_move(t_game *ptr, int key)
{
	if (key == 13 || key == 126)
		drow(ptr);
	else if (key == 2 || key == 124)
		drow(ptr);
	else if (key == 1 || key == 125)
		drow(ptr);
	else if (key == 0 || key == 123)
		drow(ptr);
}
