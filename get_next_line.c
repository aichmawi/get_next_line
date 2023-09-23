/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aichmawi <aichmawi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:54:05 by aichmawi          #+#    #+#             */
/*   Updated: 2023/02/26 12:54:13 by aichmawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readln(int fd, char *rst)
{
	int		i;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(rst, '\n') && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1 || (rst[i] == 0 && i == 0))
		{
			free(buf);
			free(rst);
			return (NULL);
		}
		buf[i] = 0;
		rst = ft_strjoin(rst, buf);
	}
	free(buf);
	return (rst);
}

char	*getln(char *rst)
{
	int		i;
	char	*line;

	i = 0;
	if (!rst)
		return (NULL);
	while (rst[i] && rst[i] != '\n')
		i++;
	if (rst[i] == 0)
		line = (char *)malloc(i + 1);
	else
		line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (rst[i] && rst[i] != '\n')
	{
		line[i] = rst[i];
		i++;
	}
	if (rst[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*restln(char *rst)
{
	char	*lastrst;
	int		j;
	int		i;

	j = 0;
	while (rst[j] && rst[j] != '\n')
		j++;
	if (!rst[j])
	{
		free(rst);
		return (NULL);
	}
	j++;
	i = ft_strlen(&rst[j]);
	lastrst = malloc(i + 1);
	if (!lastrst)
		return (NULL);
	i = 0;
	while (rst[j])
		lastrst[i++] = rst[j++];
	lastrst[i] = 0;
	free(rst);
	return (lastrst);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rst;

	if (fd == -1)
		return (NULL);
	if (!rst)
		rst = ft_strdup("");
	rst = readln(fd, rst);
	if (!rst)
		return (NULL);
	line = getln(rst);
	rst = restln(rst);
	return (line);
}
