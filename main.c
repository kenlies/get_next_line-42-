#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#define BHCYN "\e[1;96m"
#define BHMAG "\e[1;95m"
#define BHRED "\e[1;91m"
#define reset "\e[0m"

int	main(void)
{
	int		fd_0;
	int		fd_1;
	int		fd_2;
	int		i;
	char	*line[4096];
	char	*line2;

	i = 1;
	fd_0 = 0;
	fd_1 = open("text.txt", O_RDONLY);
	fd_2 = open("text2.txt", O_RDONLY);
	
	while (i < 9)
	{
		line[fd_1] = get_next_line(fd_1);
		printf(BHMAG "Line %d for fd %d: %s\n" reset, i, fd_1, line[fd_1]);
		free(line[fd_1]);
		i++;
	}
	i = 1;
	while (i < 9)
	{
		line[fd_2] = get_next_line(fd_2);
		printf(BHCYN "Line %d for fd %d: %s\n" reset, i, fd_2, line[fd_2]);
		free(line[fd_2]);
		i++;
	}
	
	while (1)
	{
		line2 = get_next_line(fd_0);
		printf(BHRED "Line %d for fd %d: %s" reset, i, fd_0, line2);
	}
	
}