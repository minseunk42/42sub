#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int		fd;
	int		ret;
	char	*buf;
	int		i;

	fd = open("numbers.dict", O_RDONLY);
	buf = (char *)malloc(4096);
	ret = read(fd, buf, 4096);
	buf[ret] = 0;
	while (*buf)
	{
		i = 0;
		while (buf[i] != '\n')
			i++;
		write(1, buf, i + 1);
		buf = buf + i + 1;
	}	
	close(fd);
}
