#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*buffer;
	int		fd;

	fd = open("a.txt", O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer != (char *)NULL)
	{
		printf("%s\n", buffer);
		buffer = get_next_line(fd);
		free(buffer);
	}
	if (buffer)
		free(buffer);
}