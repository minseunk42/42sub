#include "parse.h"
#include <stdio.h>

void	check_leak(void)
{
	system("leaks --list -- a.out");
}

int main(int argc, char *argv[])
{
	//atexit(check_leak);
	t_data *data = run_parse(argc, argv);
	printf("NO : %s\n", data->north);
	printf("SO : %s\n", data->south);
	printf("WE : %s\n", data->west);
	printf("EA : %s\n", data->east);
	printf("Floor : %d, %d, %d\n", data->floor->red, data->floor->green, data->floor->blue);
	printf("Ceiling: %d, %d, %d\n", data->ceiling->red, data->ceiling->green, data->ceiling->blue);
	int i = 0;
	
	if (!data->map[i])
		return (0);
	data->map[data->pos->y][data->pos->x] = 0;
	while ((data->map[i]))
	{
		printf("%s\n", data->map[i]);
		i++;
	}

	free_data(data);

	return (0);
	//map check, but map parse should be changed.
}
