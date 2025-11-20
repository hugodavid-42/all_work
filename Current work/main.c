#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("foo.txt", O_RDONLY);

	char *line;
	int i = 0;
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i ++;
	}
	
	line = get_next_line(fd);

	printf("%s", line);
	return 0;
}