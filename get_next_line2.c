/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:49:44 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/26 15:48:35 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// char	*ft_iread(int fd, char **get, char *line,char *rem)
// {
// 	int	i;
// 	char nlcheck;
	
// 	i = read(fd,*get,BUFFER_SIZE);
// 	*get[i] = '\0';
// 	if(get != NULL)
// 	{
// 	nlcheck = ft_strchr(*get,'\n');
// 	if(nlcheck == NULL)
// 		*line = ft_strjoin(*line, *get);
// 	else
// 	{
// 		*line = ft_strjoinplus(*line,*get, ft_strchr2(*get,'\n') + 1);
// 		*rem = ft_strjoinminnus(*get);
// 	}
	
// 	}
// 	return(NULL);
// }
// char *get_next_line2(int fd)
// {
// 	char *line;
// 	char *get;
// 	static char *rem;
// 	int i = 0;
	
// 	get = (char *)malloc(BUFFER_SIZE + 1);
// 	line = NULL;
// 	if (fd < 0 || BUFFER_SIZE < 0)
// 		return (NULL);
// 	if(rem != NULL)
// 		get = rem;
// 	else
// 		ft_iread(fd,&get,&line,&rem);
// 	return (line);
// }
// char *get_next_line2(int fd)
// {
// 	char *line;
// 	char *get;
// 	static char *rem;
// 	int i = 0;
	
// 	get = (char *)malloc(BUFFER_SIZE + 1); //free this
// 	line = NULL;
// 	if (fd < 0 || BUFFER_SIZE < 0)
// 		return (NULL);
// 	if(rem != NULL)
// 		get = rem;
// 	else
// 		get = ft_iread(fd,get);
// 	if (ft_strchr(get,'\n') == NULL)
// 		i = 1;
// 	while(ft_strchr(get,'\n') == NULL)
// 	{
// 		printf("%d\n",i);
// 		i++;
// 		line = ft_strjoin(line,get);//free
// 		get = ft_iread(fd,get);
// 	}
// 	if(ft_strchr(get,'\n') != NULL)
// 	{
// 		line = ft_strjoinplus(line,get,ft_strchr2(get,'\n') + 1); //free
// 		rem = ft_strjoinminnus(get);
// 	}
// 	// free(get);
// 	return (line);
// }

// int	main(void)
// {
// 	int fd;
// 	fd = open("twisted2.txt",O_RDONLY);
// 	printf("%s",get_next_line2(fd));
// 	printf("%s",get_next_line2(fd));
// 	close(fd);
// }