/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 01:27:21 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/22 15:57:45 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		put_line(t_hook_params s, t_line l, t_dot d, t_dot c)
{
	t_dot error;

	error.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (1)
	{
		mlx_pixel_put(s.mlx, s.window, l.x0, l.y0, l.p0_color);
		if (l.x0 == l.x1 && l.y0 == l.y1)
			break ;
		error.y = error.x;
		if (error.y > -d.x)
		{
			error.x -= d.y;
			l.x0 += c.x;
		}
		if (error.y < d.y)
		{
			error.x += d.x;
			l.y0 += c.y;
		}
	}
}

void		line(t_hook_params s, t_line l)
{
	int		x;
	int		y;
	t_dot	d;
	t_dot	c;

	c = direction(l.x0, l.y0, l.x1, l.y1);
	d = mod(l.x0, l.y0, l.x1, l.y1);
	x = l.x0;
	y = l.y0;
	l.p0_color = l.p0_color == -1 ? s.l.color : l.p0_color;
	put_line(s, l, d, c);
}

void		draw_everything(t_hook_params s)
{
	mlx_string_put(s.mlx, s.window, 880, 10, \
			0xffffff, "esc: exit");
	mlx_string_put(s.mlx, s.window, 15, 900,\
			0xffffff, "RIGHT ARROW: ROTATE RIGHT");
	mlx_string_put(s.mlx, s.window, 15, 925, \
			0xffffff, "LEFT ARROW: ROTATE LEFT");
	mlx_string_put(s.mlx, s.window, 15, 950, \
			0xffffff, "UP ARROW: ALTITUDE INCREASE");
	mlx_string_put(s.mlx, s.window, 15, 975, \
			0xffffff, "DOWN ARROW: ALTITUDE DECREASE");
	mlx_string_put(s.mlx, s.window, 700, 890, \
			0xff0000, "PRESS R: CHANGE COLOR TO RED");	
	mlx_string_put(s.mlx, s.window, 700, 920, \
			0x00ff00, "PRESS G: CHANGE COLOR RO GREEN");
	mlx_string_put(s.mlx, s.window, 700, 950, \
			0x0000ff, "PRESS B: CHANGE COLOR TO BLUE");
	dot_to_dot(s);
}

int			draw(t_hook_params s)
{
	draw_everything(s);
	mlx_key_hook(s.window, hook_keydown, &s);
	mlx_loop(s.mlx);
	return (0);
}
