/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 01:27:21 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/22 00:21:32 by yhuang           ###   ########.fr       */
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
	l.p0_color = l.p0_color == -1 ? 0xb5fd80 : l.p0_color;
	put_line(s, l, d, c);
}

void		draw_everything(t_hook_params s)
{
	mlx_string_put(s.mlx, s.window, 30, 890, \
			0xff9933, "esc: exit");
	mlx_string_put(s.mlx, s.window, 30, 910,\
			0xff9933, "RIGHT ARROW: rotate right");
	mlx_string_put(s.mlx, s.window, 30, 930, \
			0xff9933, "LEFT ARROW: rotate left");
	mlx_string_put(s.mlx, s.window, 30, 950, \
			0xff9933, "UP ARROW: ALTITUDE INCREASE");
	mlx_string_put(s.mlx, s.window, 30, 970, \
			0xff9933, "DOWN ARROW: ALTITUDE DECREASE");
	dot_to_dot(s);
}

int			draw(t_hook_params s)
{
	draw_everything(s);
	mlx_key_hook(s.window, hook_keydown, &s);
	mlx_loop(s.mlx);
	return (0);
}
