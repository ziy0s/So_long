/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:31:25 by zaissi            #+#    #+#             */
/*   Updated: 2025/02/06 16:14:20 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dst == NULL)
		return ;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

static char	*extract_line(char *storage)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!storage || *storage == '\0')
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i = i + 2;
	else
		i++;
	line = malloc(i);
	if (!line)
		return (NULL);
	ft_strlcpy(line, storage, i);
	return (line);
}

static char	*remove_line(char *storage)
{
	size_t	i;
	size_t	len;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i] || storage[i + 1] == '\0')
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	len = ft_strlen(storage) - i;
	new_storage = malloc(len);
	if (!new_storage)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	ft_strlcpy(new_storage, storage + i + 1, len);
	free(storage);
	return (new_storage);
}

static char	*read_and_store(int fd, char *storage)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*temp;

	buffer = malloc((size_t) BUFFER_SIZE + 1);
	if (!buffer)
		return (free(storage), storage = NULL, NULL);
	while (!ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(storage), storage = NULL, NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = storage;
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (free(buffer), free(temp), NULL);
		free(temp);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	storage = read_and_store(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
		return (free(storage), storage = NULL, NULL);
	storage = remove_line(storage);
	return (line);
}
