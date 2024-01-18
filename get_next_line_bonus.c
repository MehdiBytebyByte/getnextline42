/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:02:14 by mboughra          #+#    #+#             */
/*   Updated: 2024/01/18 15:27:07 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_cutback(char *line)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	diff;
	char	*str;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	len = ft_strlen(line);
	diff = len - i;
	i++;
	str = malloc(diff);
	if (!str)
		return (NULL);
	while (j < diff)
	{
		str[j] = line[i];
		j++;
		i++;
	}
	return (str);
}

char	*ft_cutfront(char *line)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	str = malloc(i + 1);
	if (!str)
		return (free(line), NULL);
	j = 0;
	while (j < i)
	{
		str[j] = line[j];
		j++;
	}
	str[j] = '\0';
	free(line);
	line = NULL;
	return (str);
}

char	*get_next_line2(char **line, char **rem, char **buf, int fd)
{
	int	i;

	i = 1;
	while (i > 0 && newcheck(*line) == 0)
	{
		i = read(fd, *buf, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		buf[0][i] = '\0';
		*line = ft_strjoin(*line, *buf);
		if (!*line)
			return (free(*rem), *rem = NULL, NULL);
	}
	if (newcheck(*line) == 1)
	{
		*rem = ft_cutback(*line);
		*line = ft_cutfront(*line);
		if (!*line)
			return (free(*rem),*rem = NULL, NULL);
	}
	return (*line);
}

int	ft_protection(int fd, char **line, int *i)
{
	if (fd < 0 || fd > OPEN_MAX)
		return (1);
	*i = 1;
	*line = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*rem[OPEN_MAX];
	char		*line;
	char		*buf;
	int			i;

	if (ft_protection(fd, &line, &i) == 1)
		return (NULL);
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || !buf)
		return (free(rem[fd]), free(buf), rem[fd] = NULL, NULL);
	if (rem[fd] != NULL)
	{
		line = ft_strjoin(line, rem[fd]);
		if (!line)
			return (free(rem[fd]), free(buf), rem[fd] = NULL, NULL);
		free(rem[fd]);
		rem[fd] = NULL;
	}
	line = get_next_line2(&line, &rem[fd], &buf, fd);
	if (!line)
		return (free(rem[fd]), free(buf), buf = NULL, rem[fd] = NULL, NULL);
	if (line[0] == 0)
		return (free(rem[fd]), rem[fd] = NULL, free(line), free(buf), NULL);
	return (free(buf), buf = NULL, line);
}
