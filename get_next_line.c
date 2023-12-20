/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:50:10 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/20 20:54:16 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *rem;
    char *buffer;
    char *total;
    char *new;
    int iterminate;
    int i;
	
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	new = (char *)malloc(BUFFER_SIZE);
	if (!buffer || !new)
		return (NULL);
	if(rem != NULL)
	{
		printf("it is not empty");
		i = 0;
		while (rem[i] != '\n')
			i++;
		if(strlen(rem) != i)
		{
			printf("IDK");
			return(NULL)
			// ft_strlcpy(rem,total + i,(strlen(total)));
			// total[i] = '\0';
			// printf("total hwa :%s",total);
			// return(total);
		}
		return("b7al b7al");
	}
	while ((iterminate = read(fd,buffer,BUFFER_SIZE)) > 0)
	{
		buffer[iterminate] = '\0';
		total = ft_strjoin(total,buffer);
		i = 0;
		while (total[i] != '\n')
			i++;
		if(i != ft_strlen(total))
		{
			rem = (char *)malloc(strlen(total));
			ft_strlcpy(rem,total + i,(strlen(total)));
			total[i] = '\0';
			printf("\n\nthe rem is %s\n\n",rem);
			return(total);
		}
	}
	free(buffer);
	free(new);
	return(total);
}
int	main(void)
{
	int fd = open("twisted2.txt",O_RDONLY);
	char *buffer;
	
	printf("%s",	get_next_line(fd));
	printf("%s",	get_next_line(fd));



	
		
	return (0);
}

