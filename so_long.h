/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:29:43 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/07 13:31:59 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>

# ifndef RESOLUTION_X
#  define RESOLUTION_X 75
# endif

# ifndef RESOLUTION_Y
#  define RESOLUTION_Y 40
# endif

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	void		*soil;
	void		*wall;
	void		*mony;
	void		*door;
	void		*player;
	t_position	player_pos;
	int			win_width;
	int			win_hight;
	int			n_coine;
	int			p_move;
	int			m_coine;
	int			n_door;
}				t_game;
char	**get_map(char *path, t_game *ptr);
void	exit_and_player(char **map, t_game **game);
void	drow(t_game *game);
void	error(char str);
void	print_move(t_game *ptr, int key);
void	do_move_w(t_game *game, int i, int y);
void	do_move_d(t_game *game, int i, int y);
void	do_move_s(t_game *game, int i, int y, int *check);
void	do_move_a(t_game *game, int i, int y);
void	b_main(t_game *ptr);
int		clean_exit(t_game *game);
int		virfy(t_game *game, int key, int y, int i);
int		check_direction(t_game *game, char s2);
int		key_hook(int key, t_game *game);
int		n_coines(char **map);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		floodfill(char **map, int x, int y, t_game **player);
void	is_valid_wall(char **str);
void	creat_stract(t_game *ptr);
void	*ft_malloc(size_t size);
void	ft_exit(int i);
void	free_map(char **str);

#endif
