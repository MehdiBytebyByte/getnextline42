#include "get_next_line.h"


int	main(void)
{
	int	fd;
	int i = 0;

	fd = open("test.txt", O_RDONLY, 0644);
	while (i < 10)
	{
		printf("%s",get_next_line(fd));
		i++;
	
	}
	return (0);
}