/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:54 by mboughra          #+#    #+#             */
/*   Updated: 2024/01/02 21:39:15 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <libc.h>

size_t	ft_strlcpy(char	*dst, char	*src, size_t	dstsize);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoinplus(char *s1, char *s2, int i);
int		ft_strchr2(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrem(char *s2);
#endif