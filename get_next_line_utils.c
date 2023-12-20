/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:57:04 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/20 20:54:22 by mboughra         ###   ########.fr       */
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
		while (src[i])
	{
		i++;
	}
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
void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;
	size_t			i;

	if (dst == src)
		return ((void *)src);
	c_dest = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	c_dest[i] = '\0';
	return (dst);
}
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
int ft_nlfinder(char *n)
{
	int i;

	i = 0;
	while (n[i] && n[i] != '\n')
		i++;
	if(ft_strlen(n) == i)
		return(-1);
	return (i);
}
char	*ft_myrealloc(char *str,int newsize)
{
	char *str2;
	str2 = (char *)malloc(newsize);
	ft_memcpy(str2,str,ft_strlen(str));
	return(str2);
}