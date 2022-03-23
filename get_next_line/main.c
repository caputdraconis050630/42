#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int		fd;
	char	*content;
	
	fd = open("test", O_RDONLY);
	content = get_next_line(fd);
	printf("%s\n", content);
}
