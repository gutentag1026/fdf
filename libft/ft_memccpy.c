/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 00:56:13 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/27 19:21:26 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		d;
	char		*copyd;
	const char	*copys;

	d = (char)c;
	copyd = (char *)dst;
	copys = (const char *)src;
	while (n--)
	{
		*copyd = *copys;
		++copyd;
		if (*copys == d)
			return (copyd);
		++copys;
	}
	return (NULL);
}
