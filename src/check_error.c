/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:06:02 by yhuang            #+#    #+#             */
/*   Updated: 2018/06/18 22:16:29 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_error(int argc, int fd)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		exit(0);
	}
	if (fd < 0 || fd == -1)
	{
		ft_putstr("Error opening file!\n");
		exit(0);
	}
}
