#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int	fd;
	char *buf;
	int i;

	fd = open("numbers.dict", O_RDONLY);
	buf = (char *)calloc(1000,1);	
	i = read(fd, buf, 1000);
	printf("i = %d, s = %s\n", i, buf);
	free(buf);
	buf = (char *)calloc(1000,1);	
	i = read(fd, buf, 1000);
	printf("i = %d, s = %s\n", i, buf);
	free(buf);
	printf("i = %d, s = %s\n", i, buf);
}
