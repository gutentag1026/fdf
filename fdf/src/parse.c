/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 00:20:04 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/21 17:54:04 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		is_hex(char *str)
{
	int	j;

	j = 0;
	while (str[j] != ' ' && str[j] != '\0')
	{
		if ((str[j] >= '0' && str[j] <= '9') || (str[j] >= 'a' \
					&& str[j] <= 'f') || (str[j] >= 'A' && str[j] <= 'F'))
			j++;
		else
			return (0);
	}
	return (j);
}

int		invalid_map(char c)
{
	if (c != ' ' && c != '-' && !ft_isdigit(c))
		return (1);
	return (0);
}

int		valid_map(char *line, int i, int *cols, int *tmp_nbr)
{
	invalid_map(line[0]);
	while (line[++i])
	{
		if (line[i] == ',' && line[i + 1] == '0' && line[i + 2] == 'x' \
				&& is_hex(&line[i + 3]))
			i += 3 + is_hex(&line[i + 3]) - 1;
		else if (line[i] == ',')
			return (1);
		else if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != '-')
			return (1);
		else if (line[i - 1] == '-' && !ft_isdigit(line[i]))
			return (1);
		else if (line[i] == '-' && line[i - 1] != ' ')
			return (1);
		if (line[i] == ' ' && (ft_isdigit(line[i - 1]) || \
					(line[i - 1] >= 'a' && line[i - 1] <= 'f') || \
					(line[i - 1] >= 'A' && line[i - 1] <= 'F')))
			(*cols)++;
	}
	if (ft_isdigit(line[i - 1]) || (line[i - 1] >= 'a' && line[i - 1] <= 'f') \
			|| (line[i - 1] >= 'A' && line[i - 1] <= 'F'))
		(*cols)++;
	if (*cols != *tmp_nbr && *tmp_nbr != -1)
		return (1);
	return (0);
}

void	read_from_file(char *line, int fd, t_map_preprocess *pre, int i)
{
	char	*tmp;
	int		tmp_nbr;

	i = 0;
	line = NULL;
	pre->data = ft_memalloc(1);
	pre->rows = 0;
	tmp_nbr = -1;
	while (get_next_line(fd, &line) > 0)
	{
		pre->cols = 0;
		if (valid_map(line, 0, &pre->cols, &tmp_nbr))
		{
			ft_putstr("invalid map!");
			exit(0);
		}
		tmp_nbr = pre->cols;
		tmp = ft_strjoin(pre->data, line);
		free(pre->data);
		free(line);
		pre->data = ft_strjoin(tmp, "\n");
		free(tmp);
		pre->rows++;
	}
}
