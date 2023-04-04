/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoutar- <hkoutar-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:46:17 by hkoutar-          #+#    #+#             */
/*   Updated: 2023/04/02 18:52:13 by hkoutar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	int		i;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	i = 1;
	while (ft_strchr(str, '\n') == 0 && i != 0)
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i == -1 || (str && *str == 0 && i == 0))
		{
			free (buf);
			free (str);
			return (NULL);
		}
		*(buf + i) = '\0';
		str = ft_strjoin(str, buf);
	}
	free (buf);
	return (str);
}

char	*get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (stash == NULL)
		return (NULL);
	while (*(stash + i) != '\n' && *(stash + i) != '\0')
		i++;
	if (*(stash + i) == '\n')
		line = (char *) malloc(i + 2);
	else
		line = (char *) malloc(i + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (*(stash + i) != '\n' && *(stash + i) != '\0')
	{
		*(line + i) = *(stash + i);
		i++;
	}
	if (*(stash + i) == '\n')
		line[i++] = '\n';
	*(line + i) = '\0';
	return (line);
}

char	*stash_rest(char *stash)
{
	int		i;
	char	*rest;
	int		j;

	i = 0;
	j = 0;
	while (*(stash + i) != '\0' && *(stash + i) != '\n')
		i++;
	if (*(stash + i) == '\0')
	{
		free (stash);
		return (NULL);
	}
	i++;
	rest = (char *)malloc(ft_strlen(stash + i) + 1);
	if (rest == NULL)
		return (NULL);
	while (*(stash + i))
		rest[j++] = stash[i++];
	*(rest + j) = '\0';
	free (stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd == -1)
		return (NULL);
	if (stash == NULL)
		stash = ft_strdup("");
	stash = read_line(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = get_line(stash);
	stash = stash_rest(stash);
	return (line);
}
