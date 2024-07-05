/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:24 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/04 16:09:45 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description :  returns a line read from a file descriptor. 
 *
 * Return value : Read line: correct behavior NULL: there is nothing else to
 * read, or an error occurred. */

#include "../../inc/get_next_line.h"
#include "../../inc/libft.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (read(fd, NULL, 0) < 0)
		return (ft_memdel(&buf));
	buf = read_until_line(fd, buf);
	if (!buf)
		return (ft_memdel(&buf));
	line = find_line(buf);
	if (!line || ft_strlen(line) == 0)
	{
		ft_memdel(&line);
		return (ft_memdel(&buf));
	}
	buf = trim_buf(buf, ft_strlen(line));
	if (!buf)
	{
		ft_memdel(&line);
		return (ft_memdel(&buf));
	}
	return (line);
}

char	*read_until_line(int fd, char *buf)
{
	char	*temp_buf;
	int		r;

	if (!buf)
		buf = ft_strdup("");
	r = 1;
	while (buf != NULL && r > 0 && ft_strchr(buf, '\n') == NULL)
	{
		temp_buf = malloc(sizeof(char) * (GNL_BUFFER_SIZE + 1));
		if (!temp_buf)
			return (ft_memdel(&buf));
		r = read(fd, temp_buf, BUFFER_SIZE);
		if (r <= 0)
		{
			ft_memdel(&temp_buf);
			if (r < 0)
				return (ft_memdel(&buf));
			return (buf);
		}
		temp_buf[r] = '\0';
		buf = gnl_strjoin(buf, temp_buf);
	}
	return (buf);
}

char	*find_line(char *buf)
{
	char	*line;
	int		i;
	int		newline;

	i = 0;
	newline = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
		newline = 1;
	line = malloc(sizeof(char) * (i + newline + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		line[i] = buf[i];
		i++;
	}
	if (newline)
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*trim_buf(char *buf, int c_g)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(buf) - c_g + 1));
	if (!res)
		return (ft_memdel(&buf));
	while (buf[c_g])
		res[i++] = buf[c_g++];
	res[i] = '\0';
	ft_memdel(&buf);
	return (res);
}
