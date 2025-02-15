/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:20:31 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/07 09:50:27 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	checker(char *str, t_game **game, int fd)
{
	int	i;
	int	n;

	if (str[0] != '1' || str[ft_strlen(str) - 2] != '1')
		return (close(fd), free(str), error('m'), 0);
	i = 0;
	n = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'P'
			&& str[i] != 'E' && str[i] != 'C' && str[i] != '\n'
			&& str[i] != 'N')
			return (close(fd), free(str), error('m'), 0);
		if (str[i] == 'P' || str[i] == 'E')
			n++;
		if (str[i] == 'C')
			(*game)->n_coine++;
		i++;
	}
	if (n > 2)
		return (close(fd), free(str), error('m'), 0);
	return (i);
}

static int	is_valid_map(int fd, int *i, t_game **ptr)
{
	int		j;
	int		check;
	char	*line;

	(*i) = 0;
	j = 0;
	check = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error('m');
	}
	while (line)
	{
		j = checker(line, ptr, fd);
		if ((*i) == 0)
			check = j;
		if (j != check)
			return (close(fd), free(line), error('m'), 0);
		(*i)++;
		free(line);
		line = get_next_line(fd);
	}
	return (check);
}

static int	ferst_check(t_game **ptr, int *i, char *path)
{
	int	res;
	int	fd;

	res = 0;
	fd = 0;
	while (path[fd])
		fd++;
	fd--;
	while (path[fd] != '.')
		fd--;
	if (ft_strncmp(path + fd, ".ber", 5))
		error('m');
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error('m');
	(*ptr)->n_coine = 0;
	res = is_valid_map(fd, i, ptr);
	close(fd);
	return (res);
}

static char	**generate_map(char *path, char **map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error('m');
	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error('m');
	}
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	enemy(map, fd);
	close(fd);
	return (map);
}

char	**get_map(char *path, t_game *ptr)
{
	int		i;
	int		check;
	char	**map;

	ptr->n_door = 0;
	check = ferst_check(&ptr, &i, path);
	if (i > RESOLUTION_Y || check > RESOLUTION_X)
		error('m');
	map = ft_malloc((i + 1) * sizeof(char *));
	if (!map)
		ft_exit(1);
	map = generate_map(path, map);
	is_valid_wall(map);
	exit_and_player(map, &ptr);
	if (ptr->n_coine
		!= floodfill(map, ptr->player_pos.x, ptr->player_pos.y, &ptr))
	{
		free_map(map);
		error('m');
	}
	return (ptr->win_hight = i, ptr->win_width = check, map);
}
