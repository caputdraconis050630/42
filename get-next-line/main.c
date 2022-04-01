#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*buffer;
	int		fd;
	int		read_size;

	buffer = (char *)malloc(sizeof(char) * 43);
	if (!buffer)
		return (0);

	fd = open("a.txt", O_RDONLY);

	read_size = read(fd, buffer, 42);
	buffer[read_size] = '\0';
	printf("%s\n", buffer);
	printf("%d\n", read_size);

	read_size = read(fd, buffer, 42);
	buffer[read_size] = '\0';
	printf("%s\n", buffer);
	printf("%d\n", read_size);

	read_size = read(fd, buffer, 42);
	buffer[read_size] = '\0';
	printf("%s\n", buffer);
	printf("%d\n", read_size);

	read_size = read(fd, buffer, 42);
	buffer[read_size] = '\0';
	printf("%s\n", buffer);
	printf("%d\n", read_size);

	
	free(buffer);
}