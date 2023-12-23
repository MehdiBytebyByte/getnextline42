/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:50:10 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/23 18:06:46 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// int	checker(char *line)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = ft_strlen(line);
// 	while (i < j && line[i] != '\n')
// 		i++;
// 	if(i == 0)
// 		return(0); //special case
// 	return (j - i); // if the difference is 0 than there is no newline;  0-0	
// }
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
int	ft_strchr2(const char *s, int c)
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
			return (i);
		i++;
	}
	return(0);
}

char *get_next_line(int fd)
{

	int i;
	char *line = NULL;
	char static *rem;
	char *fetcher;
	char *nlcheck;
	fetcher = (char *)malloc(BUFFER_SIZE + 1);
	while ((i = read(fd,fetcher,BUFFER_SIZE)) > 0)
	{
		fetcher[i] = '\0';
		nlcheck = ft_strchr(fetcher,'\n');
		// printf("\nTHE CHECK-> \"%s\"\n",nlcheck);
		// printf("\nTHE FETCHER-> \"%s\"\n",fetcher);
		if(!nlcheck){
			line = ft_strjoin(line,fetcher);
		// printf("\nTHE LINE IN THIS STATE-> \"%s\"\n",line);
		}
		else
		{
			// printf("%d",ft_strchr2(fetcher,'\n') + 1);
			line = ft_strjoinplus(line,fetcher,ft_strchr2(fetcher,'\n') + 1);
			// printf("\nTHE LINE IN THIS STATE(fl else)-> \"%s\"\n",line);
			rem = ft_strjoinminus(fetcher,ft_strchr2(fetcher,'\n'));
			printf("rem is --> %s",rem);
			break;
		}
	}
	return(line);
}


int	main(void)
{
	int fd = open("twisted2.txt",O_RDONLY);
	printf("%s",get_next_line(fd));
	// printf("\nresult ->\"%s\"\n",get_next_line(fd));

}
