/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 00:35:47 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/22 01:06:54 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define PI 3.14159265
# define DEGREE (PI / 180)
# define T 45 * DEGREE
# define S_X WIN_WIDTH * 0.2
# define S_Y WIN_HEIGHT * 0.2

typedef struct			s_map
{
	float				x;
	float				y;
	float				z;
	int					color;
}						t_map;

typedef struct			s_map_preprocess
{
	int					rows;
	int					cols;
	int					i;
	int					j;
	int					height;
	int					width;
	float				scale_z;
	char				*data;
	int					color;
	int					w;
	int					h;
	float				scale_rotate;
	float				scale;
	int					diviser;
	int					dividend;
	int					x;
	int					y;
}						t_map_preprocess;

typedef struct			s_hook_params
{
	void				*mlx;
	void				*window;
	t_map				**map_in;
	t_map				**map_out;
	t_map_preprocess	pre;
}						t_hook_params;

typedef struct			s_line
{
	int					p0_color;
	int					p1_color;
	int					x0;
	int					x1;
	int					y0;
	int					y1;
}						t_line;

typedef struct			s_dot
{
	int					x;
	int					y;
}						t_dot;

typedef struct			s_error
{
	int					x;
	int					y;
}						t_error;

typedef struct			s_draw
{
	int					err;
	int					err_new;
	int					x;
	int					y;
}						t_draw;

void					read_from_file(char *line, int fd, \
		t_map_preprocess *pre, int i);
void					check_error(int argc, int fd);
int						buf_atoi(char *s, int *i);
t_map					**create_map_in(t_map_preprocess pre, int i);
t_map					**create_map_out(t_map_preprocess pre);
void					normalize_coords(t_map **map, t_map_preprocess pre);
void					rotate(t_map **in, t_map **out, t_map_preprocess pre);
void					max_coords(t_map **map, t_map_preprocess pre);
int						draw(t_hook_params s);
int						ft_atoi_hex(const char *str, int *i);
int						is_space(char c);
int						ft_atoi_hex(const char *str, int *i);
void					free_map(t_map **map, int rows);
int						hook_keydown(int key, t_hook_params *s);
t_dot					direction(int x0, int y0, int x1, int y1);
t_dot					mod(int x0, int y0, int x1, int y1);
void					get_dot_v(t_hook_params s, int h, int w);
void					get_dot_h(t_hook_params s, int h, int w);
void					dot_to_dot(t_hook_params s);
void					line(t_hook_params s, t_line l);
void					draw_everything(t_hook_params s);

#endif
