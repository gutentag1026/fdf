/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 23:54:10 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/22 00:54:23 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			buf_atoi(char *s, int *i)
{
	int		result;

	while (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n')
		*i += 1;
	result = ft_atoi(&s[*i]);
	if (s[*i] == '+' || s[*i] == '-')
		*i += 1;
	while (ft_isdigit(s[*i]))
		*i += 1;
	return (result);
}

t_map		**memory(int height)
{
	t_map	**map;

	if (!(map = (t_map **)malloc(sizeof(t_map *) * (height))))
		return (NULL);
	return (map);
}

t_map		**create_map_in(t_map_preprocess pre, int i)
{
	t_map	**map;

	pre.height = pre.rows;
	pre.width = pre.cols;
	map = memory(pre.height);
	pre.rows = -1;
	while (++pre.rows < pre.height && (pre.cols = -1))
	{
		if (!(map[pre.rows] = (t_map*)malloc(sizeof(t_map) * (pre.width))))
			return (NULL);
		while (++pre.cols < pre.width)
		{
			map[pre.rows][pre.cols].z = buf_atoi(pre.data, &i);
			map[pre.rows][pre.cols].color = ft_atoi_hex(pre.data, &i);
			map[pre.rows][pre.cols].x = pre.cols;
			map[pre.rows][pre.cols].y = pre.rows;
		}
	}
	return (map);
}

t_map		**create_map_out(t_map_preprocess pre)
{
	t_map	**map;

	pre.height = pre.rows;
	pre.width = pre.cols;
	map = memory(pre.height);
	pre.rows = -1;
	while (++pre.rows < pre.height && (pre.cols = -1))
	{
		if (!(map[pre.rows] = (t_map*)malloc(sizeof(t_map) * (pre.width))))
			return (NULL);
		while (++pre.cols < pre.width)
		{
			map[pre.rows][pre.cols].x = 0;
			map[pre.rows][pre.cols].y = 0;
			map[pre.rows][pre.cols].z = 0;
		}
	}
	return (map);
}
