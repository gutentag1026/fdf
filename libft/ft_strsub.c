/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:52:41 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/25 03:17:32 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(fresh = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[start])
		fresh[i++] = s[start++];
	fresh[i] = '\0';
	return (fresh);
}
