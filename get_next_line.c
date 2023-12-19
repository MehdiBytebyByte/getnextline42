/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:50:10 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/19 21:33:00 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *rem;
    char *buffer = (char *)malloc(BUFFER_SIZE);
    char *total = NULL;
    char *new = (char *)malloc(BUFFER_SIZE);
    int checker;
    int i;

    if (buffer == NULL || new == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[i] = '\0';
        checker = ft_nlfinder(buffer);
        if (checker != -1)
        {
            new = (char *)malloc(checker);  // Allocate memory for 'new'
            rem = (char *)malloc(ft_strlen(buffer) - checker);  // Allocate memory for 'rem'
            
            if (new != NULL && rem != NULL) {
                ft_memcpy(new, buffer, checker);
                ft_memcpy(rem, buffer + checker, 4);
                total = ft_strjoin(total, new);
            }

            free(new);  // Free memory when no longer needed
            free(rem);  // Free memory when no longer needed
            free(buffer);  // Free memory when no longer needed
			printf("the remainning things are %s",rem);
            return total;
        }
    }

    free(buffer);  // Free memory when no longer needed
    return NULL;
}

int	main(void)
{
	int fd = open("twisted2.txt",O_RDONLY);
	char *buffer;
	
	printf("%s",	get_next_line(fd));



	
		
	return (0);
}