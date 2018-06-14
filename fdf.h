/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 00:35:47 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/13 15:03:57 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include "minilibx_macos/mlx.h"
# include <math.h>

# define win_width			1000
# define win_height			1000
# define PI 				3.14159265
# define DEGREE 			(PI / 180)
# define T					45 * DEGREE
# define S_X				win_width * 0.6
# define S_Y				win_height * 0.4
# define W_SPAN				win_width * 0.2
# define H_SPAN				win_height * 0.2

typedef struct	s_map
{
	int		x;
	int		y;
	float	z;
	int		color;

}				t_map;


typedef struct	s_map_preprocess
{
	int		rows;
	int		cols;
	int		i;
	int		j;
	float	scale_z;
	char	*data;
}				t_map_preprocess;

typedef struct  		s_hook_params
{
	void				*mlx;
	void				*window;
	t_map				**map;
	t_map_preprocess	pre;
}						t_hook_params;

typedef struct	s_line
{
	int		p0_color;
	int		p1_color;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
}				t_line;

typedef struct	s_dot
{
	int		x;
	int		y;
}				t_dot;

typedef struct	s_error
{
	int		x;
	int		y;
}				t_error;

typedef struct s_draw
{
	int		err;
	int		err_new;
	int		x;
	int		y;
}				t_draw;


void	read_from_file(char *line, int fd, t_map_preprocess *pre, int i);
void	check_error(int argc, int fd);
int		buf_atoi(char *s, int *i);
t_map	**create_map(t_map_preprocess pre, int i);
int		draw(t_map **map, int h, int w);
int  	ft_atoi_hex(const char *str, int *i);
#endif
