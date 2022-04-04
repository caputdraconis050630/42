#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*buffer;
	int		fd;
	int		read_size;

	fd = open("a.txt", O_RDONLY);
	for(int i = 0; i < 20; i++)
	{
		buffer = get_next_line(fd);
		printf("%d 번째 read\n", i + 1);
		printf("%s\n\n\n", buffer);
	}
}