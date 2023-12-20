/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:54 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/20 20:54:25 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
# endif

#include <libc.h>

size_t	ft_strlcpy(char	*dst, char	*src, size_t	dstsize);
size_t	ft_strlen(char *str);
char 	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_nlfinder(char *n);
char	*ft_myrealloc(char *str,int newsize);
#endif