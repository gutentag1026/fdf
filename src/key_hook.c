/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 19:51:31 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/21 19:27:53 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			hook_keydown(int key, t_hook_params *s)
{
	if (key == 53)
	{	
		free_map(s->map_in, s->pre.rows);
		free_map(s->map_out, s->pre.rows);
		mlx_destroy_window(s->mlx, s->window);
		exit(EXIT_SUCCESS);
	}
	if (key == 124)
	{
		s->pre.scale_rotate += 10;
		rotate(s->map_in, s->map_out, s->pre);
		max_coords(s->map_out, s->pre);
		mlx_clear_window(s->mlx, s->window);
		draw(*s);
	}
	if (key == 123)
	{
		s->pre.scale_rotate -= 10;
		rotate(s->map_in, s->map_out, s->pre);
		max_coords(s->map_out, s->pre);
		mlx_clear_window(s->mlx, s->window);
		draw(*s);
	}
	if (key == 126)
	{
		s->pre.scale_z += 0.5;
		rotate(s->map_in, s->map_out, s->pre);
		max_coords(s->map_out, s->pre);
		mlx_clear_window(s->mlx, s->window);
		draw(*s);
	}
	if (key == 125)
	{
		s->pre.scale_z -= 0.5;
		rotate(s->map_in, s->map_out, s->pre);
		max_coords(s->map_out, s->pre);
		mlx_clear_window(s->mlx, s->window);
		draw(*s);
	}
	return (0);
}
