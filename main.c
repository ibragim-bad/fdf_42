#include "./minilibx/mlx.h"
#include "fdf.h"
#include <stdlib.h>



int	main(int ac, char *av[])
{
	int	fd;
	t_pix *pxls;
	char	*gnl_line;
	int a;

	gnl_line = (char *)ft_memalloc(1000);
	if (ac != 2)
		write(1, "usage: fdf \"name of file\"\n", 26);
	if (!(fd = open(av[1], O_RDONLY)))
		write(1, "error\n", 6);
	while (a = get_next_line(fd, &gnl_line))
		1;
	printf("%s\n", gnl_line);
/* 	gnl_line;
	pxls = get_matrix(gnl_line);
	window(); */
	return (0);
}
