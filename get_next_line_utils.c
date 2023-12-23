/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:57:04 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/23 17:55:35 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (strdup(s2));
	if (!s2)
		return (strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc(s1len + s2len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy (str, s1, s1len + 1);
	ft_strlcpy (str + s1len, s2, s2len + 1);
	str[s1len + s2len] = '\0';
	return (str);
}
size_t	ft_strlcpy(char	*dst,char	*src, size_t	dstsize)
{
	size_t	i;
	char	*s;

	if (dstsize == 0)
		return (ft_strlen(src));
	s = (char *)src;
	i = 0;
	while (src[i] && i < (dstsize -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoinplus(char *s1, char *s2,int i)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		str = malloc(i + 1);
		ft_strlcpy(str, s2, i + 1);
		return(str);
	}
	if (!s2)
		return (strdup(s1));
	s1len = ft_strlen(s1);
	str = (char *)malloc(s1len + i + 1);
	if (!str)
		return (NULL);
	ft_strlcpy (str, s1, s1len + 1);
	ft_strlcpy (str + s1len, s2, i + 1);
	return (str);
}
char    *ft_strjoinminus(char *s2,int i)
{
    char    *str;
    size_t    s2len;
    int diff;

    if (!s2)
        return (NULL);
    s2len = ft_strlen(s2);
    diff = s2len - i;
    str = (char *)malloc(diff);
    if (!str)
        return (NULL);
    ft_strlcpy (str,s2 + i + 1, diff);
    return (str);
}