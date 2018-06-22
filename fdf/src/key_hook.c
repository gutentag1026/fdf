/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 19:51:31 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/22 15:57:41 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotate_right(t_hook_params *s)
{
	s->pre.scale_rotate += 10;
	rotate(s->map_in, s->map_out, s->pre);
	max_coords(s->map_out, s->pre);
	mlx_clear_window(s->mlx, s->window);
	draw(*s);
}

void		rotate_left(t_hook_params *s)
{
	s->pre.scale_rotate -= 10;
	rotate(s->map_in, s->map_out, s->pre);
	max_coords(s->map_out, s->pre);
	mlx_clear_window(s->mlx, s->window);
	draw(*s);
}

void		arrow_up(t_hook_params *s)
{
	s->pre.scale_z += 0.01;
	rotate(s->map_in, s->map_out, s->pre);
	max_coords(s->map_out, s->pre);
	mlx_clear_window(s->mlx, s->window);
	draw(*s);
}

void		arrow_down(t_hook_params *s)
{
	s->pre.scale_z -= 0.01;
	rotate(s->map_in, s->map_out, s->pre);
	max_coords(s->map_out, s->pre);
	mlx_clear_window(s->mlx, s->window);
	draw(*s);
}

void		color_red(t_hook_params *s)
{
	s->l.color = 0xff0000;
	mlx_clear_window(s->mlx, s->window);
	draw(*s);
}

void		color_green(t_hook_params *s)
{
	s->l.color = 0x00ff00;
	mlx_clear_window(s->mlx, s->window);
	draw(*s);
}

void		color_blue(t_hook_params *s)
{
	s->l.color = 0x0000ff;
	mlx_clear_window(s->mlx, s->window);
	draw(*s);
}

int			hook_keydown(int key, \
		t_hook_params *s)
{
	if (key == 53)
	{
		free_map(s->map_in, s->pre.rows);
		free_map(s->map_out, s->pre.rows);
		mlx_destroy_window(s->mlx, s->window);
		exit(EXIT_SUCCESS);
	}
	if (key == 124)
		rotate_right(s);
	if (key == 123)
		rotate_left(s);
	if (key == 126)
		arrow_up(s);
	if (key == 125)
		arrow_down(s);
	if (key == 15)
		color_red(s);
	if (key == 11)
		color_blue(s);
	if (key == 5)
		color_green(s);
	return (0);
}
