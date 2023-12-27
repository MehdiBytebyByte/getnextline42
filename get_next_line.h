/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:54 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/27 00:02:47 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif

#include <libc.h>

size_t	ft_strlcpy(char	*dst, char	*src, size_t	dstsize);
size_t	ft_strlen(char *str);
char 	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoinplus(char *s1, char *s2,int i);
// char	*ft_strjoinminus(char *s2,int i);
// char    *ft_strjoinminnus(char *s2);
int		ft_strchr2(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char    *ft_strrem(char *s2);
#endif