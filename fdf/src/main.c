/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 00:45:05 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/22 15:57:43 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	int					fd;
	char				*line;
	t_map_preprocess	pre;
	t_hook_params		s;
	t_line				l;

	pre.j = 0;
	pre.i = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	check_error(argc, fd);
	read_from_file(line, fd, &pre, 0);
	if (close(fd) < 0)
		ft_putstr("Error closing file!\n");
	pre.scale_rotate = 45;
	pre.scale_z = 0.2;
	s.map_in = create_map_in(pre, 0);
	s.map_out = create_map_out(pre);
	rotate(s.map_in, s.map_out, pre);
	max_coords(s.map_out, pre);
	s.pre = pre;
	s.mlx = mlx_init();
	s.window = mlx_new_window(s.mlx, WIN_WIDTH, WIN_HEIGHT, "Super FDF");
	l.color = 0xffff00;
	s.l = l;
	draw(s);
}
