/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 23:40:08 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/27 19:25:26 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *strend;

	strend = s1 + ft_strlen(s1);
	while (*s2)
	{
		*strend = *s2;
		strend++;
		s2++;
	}
	*strend = '\0';
	return (s1);
}
