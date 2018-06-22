/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 19:52:53 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/21 19:00:08 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_dot		direction(int x0, int y0, int x1, int y1)
{
	t_dot	s;

	s.x = x0 < x1 ? 1 : -1;
	s.y = y0 < y1 ? 1 : -1;
	return (s);
}

t_dot		mod(int x0, int y0, int x1, int y1)
{
	t_dot	d;

	d.x = abs(x0 - x1);
	d.y = abs(y0 - y1);
	return (d);
}

void		get_dot_v(t_hook_params s, int h, int w)
{
	t_line	l;
	t_map	**map;

	map = s.map_out;
	while (++h < s.pre.rows && (w = -1))
	{
		while (++w < s.pre.cols - 1)
		{
			l.p0_color = map[h][w].color;
			l.p1_color = map[h][w + 1].color;
			l.x0 = map[h][w].x;
			l.x1 = map[h][w + 1].x;
			l.y0 = map[h][w].y;
			l.y1 = map[h][w + 1].y;
			line(s, l);
		}
	}
}

void		get_dot_h(t_hook_params s, int h, int w)
{
	t_line	l;
	t_map	**map;

	map = s.map_out;
	while (++w < s.pre.cols && (h = -1))
	{
		while (++h < s.pre.rows - 1)
		{
			l.p0_color = map[h][w].color;
			l.p1_color = map[h + 1][w].color;
			l.x0 = map[h][w].x;
			l.x1 = map[h + 1][w].x;
			l.y0 = map[h][w].y;
			l.y1 = map[h + 1][w].y;
			line(s, l);
		}
	}
}

void		dot_to_dot(t_hook_params s)
{
	get_dot_v(s, -1, -1);
	get_dot_h(s, -1, -1);
}
