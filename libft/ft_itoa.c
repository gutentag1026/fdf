/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 00:33:05 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/28 15:13:52 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char		*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	is_neg(&n, &neg);
	len = ft_digitlen(n) + neg;
	if (!(s = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		s[0] = '0';
	s[len] = '\0';
	while (n)
	{
		s[--len] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
