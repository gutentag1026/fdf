/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:24:01 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/27 19:30:29 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*string;
	unsigned char		l;

	string = (unsigned char*)s;
	l = (unsigned char)c;
	while (n--)
	{
		if (*string == l)
			return ((void*)string);
		string++;
	}
	return (NULL);
}
