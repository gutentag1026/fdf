/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:08:58 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/27 15:02:29 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		src_len;
	size_t		j;
	size_t		n;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	n = size - dst_len - 1;
	j = 0;
	if (dst_len >= size)
		return (size + src_len);
	else
	{
		while (n--)
		{
			dst[dst_len + j] = src[j];
			if (src[j] == '\0')
				return (dst_len + src_len);
			j = j + 1;
		}
		dst[dst_len + j] = '\0';
		return (dst_len + src_len);
	}
}
