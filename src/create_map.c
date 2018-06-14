/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 19:24:38 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/11 18:59:47 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		buf_atoi(char *s, int *i)
{
	int	result;
	while (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n')
		*i += 1;
	result = ft_atoi(&s[*i]);
	if (s[*i] == '+' || s[*i] == '-')
		*i += 1;
	while (ft_isdigit(s[*i]))
		*i += 1;
	return (result);
}

t_map		**create_map(t_map_preprocess pre, int i)
{
	t_map 	**map;
	int		height;
	int 	width;

	height = pre.rows;
	width = pre.cols;
	if (!(map = (t_map**)malloc(sizeof(t_map*) * (height))))
	   return (NULL);
	pre.rows = -1;
	while (++pre.rows < height && (pre.cols = -1))
	{
		if (!(map[pre.rows] = (t_map*)malloc(sizeof(t_map) * (width))))
			return (NULL);
		while(++pre.cols < width)
		{			
			map[pre.rows][pre.cols].z = buf_atoi(pre.data, &i) * pre.scale_z;	
			map[pre.rows][pre.cols].color = ft_atoi_hex(pre.data, &i);
			map[pre.rows][pre.cols].x = S_X + pre.cols * W_SPAN / width;
			map[pre.rows][pre.cols].x -= pre.rows * (win_width * 0.4 / height);
			map[pre.rows][pre.cols].y = S_Y + pre.rows * H_SPAN / height;
			map[pre.rows][pre.cols].y += pre.cols * (win_height * 0.4 / height) * 0.4 ;			
			map[pre.rows][pre.cols].y -= map[pre.rows][pre.cols].z / 20 * H_SPAN / height;
		}
	}
	return (map);
}
