/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 00:45:05 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/13 14:59:11 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int 	main(int argc, char **argv)
{
	int 				fd;
	char 				*line;
	t_map 				**map;
	t_map_preprocess	pre;
	int					num;
	
	pre.j = 0;
	pre.i = 0;
	line = NULL;
	num = 0;
	fd = open(argv[1],O_RDONLY);
	check_error(argc, fd);
	read_from_file(line, fd, &pre, 0);
	if (close(fd) < 0)
		ft_putstr("Error closing file!\n");
	pre.scale_z = 1;
//	while ((num = buf_atoi(pre.data,&pre.i)))
		if (num > 100)
			pre.scale_z =  20.0 / (num);
	map = create_map(pre, 0);
	draw(map, pre.rows, pre.cols);
//	printf("upper left z: %d\n", map[0][0].z);
}
