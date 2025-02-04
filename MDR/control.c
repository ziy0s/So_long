/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 23:24:03 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/03 21:19:36 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	do_move_w(t_game *game, int i, int y)
{
	int	size;

	size = 32;
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/back.xpm", &size, &size);
	if (!game->player)
		error('m');
	if (game->map[y - 1][i] == 'E' && n_coines(game->map) == 0)
	{
		write(1, "You Win in game !!!\n", 20);
		ft_exit(0);
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
		error('m');
	if (game->map[y][i + 1] == 'C' || (game->map[y][i + 1] == 'E'
			&& n_coines(game->map) != 0))
		game->map[y][i + 1] = '0';
	else if (game->map[y][i + 1] == 'E' && n_coines(game->map) == 0)
	{
		write(1, "You Win in game !!!\n", 20);
		ft_exit(0);
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
		error('m');
	if (game->map[y + 1][i] == 'C' || (game->map[y + 1][i] == 'E'
			&& n_coines(game->map) != 0))
		game->map[y + 1][i] = '0';
	else if (game->map[y + 1][i] == 'E' && n_coines(game->map) == 0)
	{
		write(1, "You Win in game !!!\n", 20);
		ft_exit(0);
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
		error('m');
	if (game->map[y][i - 1] == 'C' || (game->map[y][i - 1] == 'E'
			&& n_coines(game->map) != 0))
		game->map[y][i - 1] = '0';
	else if (game->map[y][i - 1] == 'E' && n_coines(game->map) == 0)
	{
		write(1, "You Win in game !!!\n", 20);
		ft_exit(0);
	}
	game->map[y][i] = '0';
	game->map[y][i - 1] = 'P';
	game->p_move++;
}

void	print_move(t_game *ptr, int key)
{
	if (key == 13 || key == 126)
		ft_printf("Number of Moves is : %d\n", ptr->p_move);
	else if (key == 2 || key == 124)
		ft_printf("Number of Moves is : %d\n", ptr->p_move);
	else if (key == 1 || key == 125)
		ft_printf("Number of Moves is : %d\n", ptr->p_move);
	else if (key == 0 || key == 123)
		ft_printf("Number of Moves is : %d\n", ptr->p_move);
}
