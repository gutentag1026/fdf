/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:54:58 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/27 19:27:15 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int j;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] !=
			'\0' && haystack[i] != '\0')
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
