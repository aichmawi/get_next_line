/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aichmawi <aichmawi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:54:35 by aichmawi          #+#    #+#             */
/*   Updated: 2023/02/26 12:54:41 by aichmawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char	*s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		l;
	int		i;

	i = 0;
	l = ft_strlen(s1) + 1;
	p = (char *) malloc (l);
	if (!p)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*k;
	int		j;

	i = ft_strlen(s1);
	l = ft_strlen(s2);
	k = (char *) malloc (i + l + 1);
	if (!k)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		k[j++] = s1[i++];
	l = 0;
	while (s2[l])
		k[j++] = s2[l++];
	k[j] = '\0';
	free(s1);
	return (k);
}
