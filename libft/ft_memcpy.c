/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:50:10 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/27 18:52:37 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*copyd;
	unsigned char		*copys;

	copyd = (unsigned char*)dst;
	copys = (unsigned char*)src;
	copys = copys + n - 1;
	copyd = copyd + n - 1;
	while (n > 0)
	{
		*copyd-- = *copys--;
		n--;
	}
	return (dst);
}
