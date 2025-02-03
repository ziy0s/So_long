/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:34:54 by zaissi            #+#    #+#             */
/*   Updated: 2025/01/30 18:29:34 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE INT_MAX
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*get_next_line_utils(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s, const char *s2);
char	*ft_strdup(const char *s1);

#endif
