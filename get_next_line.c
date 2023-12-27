/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:50:10 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/27 00:15:11 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_iread(int fd, char **fetcher,char **rem, char **line)
{
	char *nlcheck;
	int i;

	if (*rem != NULL)
	{
        *fetcher = *rem;
		*rem = NULL;
	}
	else
	{
		i = read(fd, *fetcher,BUFFER_SIZE);
		if (i <= 0)
			return (0);
		fetcher[0][i] = '\0';
	}
	nlcheck = ft_strchr(*fetcher,'\n');
	if(nlcheck != NULL)
	{
		*line = ft_strjoinplus(*line, *fetcher, ft_strchr2(*fetcher,'\n') + 1);
		*rem = ft_strrem(*fetcher);
		return(2);
	}
	if(nlcheck == NULL)
		*line = ft_strjoin(*line,*fetcher);
	return (1);
}

char *get_next_line(int fd)
{
	int i;
	char *line = NULL;
	static char *rem;
	char *fetcher;
	
	i = 1;
	fetcher = (char *)malloc(BUFFER_SIZE + 1);
	if(fd < 0 || !fetcher || BUFFER_SIZE < 0)
		return(NULL);
	while (i == 1)
		i = ft_iread(fd, &fetcher, &rem, &line);
	if (i < 0)
		return(NULL);
	return(free(fetcher),line);
}
// int	main(void)
// {
// 	int fd = open("twisted2.txt",O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	close(fd);
// }







































// char *get_next_line(int fd)
// {

// 	int i;
// 	char *line = NULL;
// 	static char *rem;
// 	char *fetcher;
// 	char *nlcheck;
	
// 	fetcher = (char *)malloc(BUFFER_SIZE + 1);
// 	if(fd < 0 || !fetcher || BUFFER_SIZE < 0)
// 		return(NULL);
// 	if (rem)
// 	{
// 		fetcher = rem;
// 		nlcheck = ft_strchr(fetcher,'\n');
// 		if(!nlcheck){
// 			line = ft_strjoin(line,fetcher);
// 			printf("line hna -> %s",line);
// 	}
// 		else
// 		{
// 			line = ft_strjoinplus(line,fetcher,ft_strchr2(fetcher,'\n') + 1);
// 			rem = ft_strrem(fetcher);
// 		}
// 	}
// 	while ((i = read(fd,fetcher,BUFFER_SIZE)) > 0 && !rem)
// 	{
// 		fetcher[i] = '\0';
// 		nlcheck = ft_strchr(fetcher,'\n');
// 		if(!nlcheck)
// 			line = ft_strjoin(line,fetcher);
// 		else
// 		{
// 			line = ft_strjoinplus(line,fetcher,ft_strchr2(fetcher,'\n') + 1);
// 			rem = ft_strrem(fetcher);
// 		}
// 	}
// 	printf("\nrem->%s<-\n",rem);
// 	return(line);
// }



