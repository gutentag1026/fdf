#include "../fdf.h"

void	check_error(int argc, int fd)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		exit(0);
	}
	if (fd < 0 || fd == -1)
	{
		ft_putstr("Error opening file!\n");
		exit(0);
	}
}
