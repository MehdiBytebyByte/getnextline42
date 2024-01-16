/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:50:10 by mboughra          #+#    #+#             */
/*   Updated: 2024/01/16 17:19:39 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char	*s1, char	*s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc(s1len + s2len + 1);
	if (!str)
		return(NULL);
		// return (free(s2),s2 = NULL, NULLls;
	ft_strlcpy (str, s1, s1len + 1);
	ft_strlcpy (str + s1len, s2, s2len + 1);
	free(s1);
	s1 = NULL;
	return (str);
}

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
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = line[j];
		j++;
	}
	str[j] = '\0';
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
			// return (free(buf), buf = NULL ,free (rem) , rem = NULL, free(line), line = NULL, NULL);
		buf[0][i] = '\0';
		*line = ft_strjoin(*line, *buf);
		// if(!*line)
		// 	return(NULL);
	}
	if (newcheck(*line) == 1)
	{
		*rem = ft_cutback(*line);
		*line = ft_cutfront(*line);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*line;
	char		*buf;
	int			i;

	i = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(rem), rem = NULL, NULL);
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (free(rem), rem = NULL, NULL);
	if (rem != NULL)
		line = ft_strjoin(line, rem);
	line = get_next_line2(&line, &rem, &buf, fd);
	if(line[0] == 0)
		return(free(line),free(buf),free(rem),buf = NULL, line = NULL ,rem = NULL,line);
	return (free(buf),buf = NULL,line);
}
