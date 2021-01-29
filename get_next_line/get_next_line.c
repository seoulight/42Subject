/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:39:59 by gkim              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/29 15:56:44 by gkim             ###   ########.fr       */
=======
/*   Updated: 2021/01/23 12:47:15 by gkim             ###   ########.fr       */
>>>>>>> 8f5c2d6c12830bc13b21728be900a0d03b90df99
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_buf(char *save, char *buf)
{
	char *tmp;

	if (!(tmp = ft_strjoin(save, buf)))
	{
		free(save);
		free(buf);
	}
	else
		free(save);
<<<<<<< HEAD
	}
=======
>>>>>>> 8f5c2d6c12830bc13b21728be900a0d03b90df99
	return (tmp);
}

int		cut_save(char **line, char **save, char *buf, char *cutp)
{
	char	*tmp;

	free(buf);
	*cutp = '\0';
	if (!(*line = ft_strdup(*save)) ||
			!(tmp = ft_strdup(cutp + 1)))
	{
		free(*save);
		*save = 0;
		return (-1);
	}
	free(*save);
	*save = tmp;
	return (1);
}

int		get_line(char **line, char **save, char *buf)
{
	char	*tmp;

	free(buf);
	buf = 0;
	if ((tmp = ft_strchr(*save, '\n')))
		return (cut_save(line, save, buf, tmp));
	if (*save)
	{
		*line = *save;
		*save = 0;
	}
	else
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		*buf;
	char		*cutp;
	ssize_t		bytes;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0 ||
	!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if (!(save[fd] = add_buf(save[fd], buf)))
			return (-1);
		if ((cutp = ft_strchr(save[fd], '\n')))
			return (cut_save(line, &save[fd], buf, cutp));
	}
	if (bytes < 0)
	{
		free(buf);
		return (-1);
	}
	return (get_line(line, &save[fd], buf));
}
