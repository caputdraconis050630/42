#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*buffer;
	int		fd;
	int		read_size;

	fd = open("a.txt", O_RDONLY);
	for(int i = 0; i < 50; i++)
	{
		printf("%d 번째 read\n", i + 1);
		buffer = get_next_line(fd);
		printf("%s\n", buffer);
	}
}