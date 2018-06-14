/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 01:27:21 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/13 18:28:00 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
int  is_space(char c)
{
  return ( c == '\t'|| c == '\v'|| c == '\f' || c == '\n' || c == '\r' || c == ' ');
}   
      
int  ft_atoi_hex(const char *str, int *i)
{
	int	j;
	int	nbr;

	j = 0;
	nbr = 0;

	if (!str[*i] || is_space(str[*i]))
	   return (-1);
	*i += 3;	
	while (j < 6 && !is_space(str[*i]) && str[*i])
	{
		if (str[*i] >= 'A' && str[*i] <= 'F')
			nbr = nbr * 16 + (str[*i] - 'A' + 10);
		else if (str[*i] >= 'a' && str[*i] <= 'f')
			nbr = nbr * 16 + (str[*i] - 'a' + 10);
		else if (str[*i] >= '0' && str[*i] <= '9')
			nbr = nbr * 16 + (str[*i] - '0');
		else
			return (-1);
		(*i)++;
		j++;
	}
 	return (nbr);
}

t_dot	direction(int x0, int y0, int x1, int y1)
{
	t_dot	s;
	
	s.x = x0 < x1 ? 1 : -1;
	s.y = y0 < y1 ? 1 : -1;
	return (s);
}

t_dot	mod(int x0, int y0, int x1, int y1)
{
	t_dot	d;

	d.x = abs(x0 - x1);
	d.y = abs(y0 - y1);
	return (d);
}

void	put_line(t_hook_params s, t_line l, t_dot d, t_dot c)
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


int		getcolor(int z0, int z1)
{
	if (z0 > 7 || z1 >7)
		return (0xFF0000);
	return (0xAAAAAA);
}

void	line(t_hook_params s, t_line l)
{
	int		x;
	int		y;
	t_dot	d;
	t_dot   c;

	c = direction(l.x0, l.y0, l.x1, l.y1);
	d = mod(l.x0, l.y0, l.x1, l.y1);
	x = l.x0;
	y = l.y0;
	l.p0_color = l.p0_color ==  -1  ? getcolor(l.p0_color, l.p1_color) : l.p0_color;
	put_line(s, l, d, c);
}


void	free_map(t_map **map)
{
	(void)map;
}


void	dot_to_dot(t_map **map, t_hook_params s)
{
	int		height;
	int		width;
	int		h;
	int		w;

	t_line	l;
	height = s.pre.rows;
	width = s.pre.cols;
	h = -1;
	while (++h < height && (w = -1))
	{	
		while (++w < width -1)
		{
			l = (t_line){ .p0_color = map[h][w].color, .p1_color = map[h][w + 1].color, .x0=map[h][w].x, .x1=map[h][w + 1].x, .y0 = map[h][w].y, .y1 = map[h][w + 1].y};	
			line(s, l);
		}
	}
	w = -1;
	while (++w < width && (h = -1))
	{
		while (++h < height - 1)
		{
			l = (t_line){ .p0_color = map[h][w].color, .p1_color = map[h + 1][w].color, .x0=map[h][w].x, .x1=map[h + 1][w].x, .y0=map[h][w].y, .y1=map[h + 1][w].y};
			line(s, l);
		}
	}
}

void	draw_everything(t_hook_params s)
{


	mlx_clear_window(s.mlx,s.window);
	mlx_string_put(s.mlx, s.window, 20, 20, 0xff9933, "esc: exit");
	mlx_string_put(s.mlx, s.window, 20, 40, 0xff9933, "esc: exit");
	mlx_string_put(s.mlx, s.window, 20, 60, 0xff9933, "esc: exit");
	dot_to_dot(s.map, s);

}

int		hook_keydown(int key, t_hook_params *s)
{
	if (key == 53)
	{
		mlx_destroy_window(s->mlx, s->window);
		exit(EXIT_SUCCESS);
	}
	if (key == 123)
	{
		s->pre.scale_z += 100;
		free_map(s->map);
		s->map = create_map(s->pre,0);
		draw_everything(*s);
	}
	if (key == 124)
	{
		s->pre.scale_z -= 100;
		free_map(s->map);
		s->map = create_map(s->pre,0);
		draw_everything(*s);
	}
	return (0);
}

void	set_color(int *map, unsigned char red, unsigned char green, unsigned char blue)
{
	if (!map)
		return ;
	*map = 65536 * red + 256 * green + blue;
}




int		draw(t_map **map, int h, int w)
{

	t_hook_params	s;
	s.map = map;
 	s.pre.rows = h;
 	s.pre.cols = w;
	s.mlx = mlx_init();
	s.window = mlx_new_window(s.mlx, win_width, win_height, "Super FDF");
	
	draw_everything(s);
	
	mlx_key_hook (s.window, hook_keydown, &s);
	mlx_loop(s.mlx);
	return (0);
}
