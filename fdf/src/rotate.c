/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:29:40 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/22 15:05:19 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		normalize_helper(t_map **map, \
		t_map_preprocess pre, float min_y, float min_x)
{
	int		y;
	int		x;

	y = 0;
	while (y < pre.rows)
	{
		x = 0;
		while (x < pre.cols)
		{
			map[y][x].x += -min_x + 1;
			map[y][x].y += -min_y + 1;
			x++;
		}
		y++;
	}
}

void		normalize_coords(t_map **map, t_map_preprocess pre)
{
	float		lowest_x;
	float		lowest_y;
	int			y;
	int			x;

	y = 0;
	x = 0;
	lowest_x = map[y][x].x;
	lowest_y = map[y][x].y;
	while (y < pre.rows)
	{
		x = 0;
		while (x < pre.cols)
		{
			if (map[y][x].x < lowest_x)
				lowest_x = map[y][x].x;
			if (map[y][x].y < lowest_y)
				lowest_y = map[y][x].y;
			x++;
		}
		y++;
	}
	normalize_helper(map, pre, lowest_y, lowest_x);
}

void		rotate(t_map **in, t_map **out, t_map_preprocess pre)
{
	int			y;
	int			x;
	double		rad;

	rad = pre.scale_rotate * DEGREE;
	y = 0;
	while (y < pre.rows)
	{
		x = 0;
		while (x < pre.cols)
		{
			out[y][x].x = in[y][x].x * cos(rad) - in[y][x].y * sin(rad);
			out[y][x].y = in[y][x].y * cos(rad) + in[y][x].x * sin(rad) \
				- (in[y][x].z * pre.scale_z);
			out[y][x].z = in[y][x].z;
			out[y][x].color = in[y][x].color;
			x++;
		}
		y++;
	}
	normalize_coords(out, pre);
}

t_map		**expand(t_map **map, t_map_preprocess pre, int max_y, int max_x)
{
	int		x;
	int		y;

	pre.dividend = max_y > max_x ? max_y : max_x;
	pre.diviser = WIN_WIDTH;
	pre.scale = pre.diviser / (pre.dividend + 1);
	y = 0;
	while (y < pre.rows)
	{
		x = 0;
		while (x < pre.cols)
		{
			map[y][x].x *= pre.scale;
			map[y][x].y *= pre.scale;
			x++;
		}
		y++;
	}
	return (map);
}

void		max_coords(t_map **map, t_map_preprocess pre)
{
	float	max_x;
	float	max_y;
	int		y;
	int		x;

	y = 0;
	x = 0;
	max_x = map[y][x].x;
	max_y = map[y][x].y;
	while (y < pre.rows)
	{
		x = 0;
		while (x < pre.cols)
		{
			if (map[y][x].x > max_x)
				max_x = map[y][x].x;
			if (map[y][x].y > max_y)
				max_y = map[y][x].y;
			x++;
		}
		y++;
	}
	expand(map, pre, max_y, max_x);
}
