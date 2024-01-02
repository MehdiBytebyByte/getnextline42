/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:50:10 by mboughra          #+#    #+#             */
/*   Updated: 2024/01/02 22:42:14 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*char_s;
	char	char_c;
	size_t	i;

	i = 0;
	char_c = (char)c;
	char_s = (char *)s;
	while (char_s[i])
	{
		if (char_s[i] == char_c)
			return (&char_s[i]);
		i++;
	}
	if (char_c == '\0')
		return (&char_s[i]);
	return (NULL);
}

int	ft_nlindex(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int	ft_iread(int fd, char **fetcher, char **rem, char **line)
{
	char	*nlcheck;
	int		i;

	if (*rem != NULL)
	{
		*fetcher = *rem;
		*rem = NULL;
	}
	else
	{
		i = read(fd, *fetcher, BUFFER_SIZE);
		if (i <= 0)
			return (0);
		fetcher[0][i] = '\0';
	}
	nlcheck = ft_strchr(*fetcher, '\n');
	if (nlcheck != NULL)
	{
		*line = ft_strjoinplus(*line, *fetcher, ft_nlindex(*fetcher));
		*rem = ft_strrem(*fetcher);
		return (2);
	}
	if (nlcheck == NULL)
		*line = ft_strjoin(*line, *fetcher);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*line;
	char		*fetcher;
	int			i;

	line = NULL;
	i = 1;
	fetcher = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || !fetcher || BUFFER_SIZE < 0)
		return (NULL);
	while (i == 1)
		i = ft_iread(fd, &fetcher, &rem, &line);
	if (i < 0)
		return (NULL);
	return (free(fetcher), line);
}
