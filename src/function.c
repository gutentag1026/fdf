/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 19:44:59 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/21 19:26:56 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			is_space(char c)
{
	return (c == '\t' || c == '\v' || c == '\f' || \
			c == '\n' || c == '\r' || c == ' ');
}

int			ft_atoi_hex(const char *str, int *i)
{
	int		j;
	int		nbr;

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

void		free_map(t_map **map, int rows)
{
	int	i;

	i = -1;
	while (++i < rows)
		free(map[i]);
	free(map);
}
