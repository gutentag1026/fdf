/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:14:09 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/25 01:35:57 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *d;

	d = dst;
	if (!len)
		return (dst);
	while (*src != '\0' && len)
	{
		*dst++ = *src++;
		len--;
	}
	while (len)
	{
		*dst++ = '\0';
		len--;
	}
	return (d);
}
