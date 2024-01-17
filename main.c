#include "get_next_line.h"
#include <fcntl.h>


int	main(void)
{
	int fd = open("test.txt",O_RDONLY,0644);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}