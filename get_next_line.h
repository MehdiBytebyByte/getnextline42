/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:54 by mboughra          #+#    #+#             */
/*   Updated: 2024/01/16 17:00:56 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <libc.h>

size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char	*dst, char	*src, size_t	dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		newcheck(char *str);
char	*ft_cutfront(char *line);
char	*ft_cutback(char *line);
char	*ft_strdup(char *s1);


#endif