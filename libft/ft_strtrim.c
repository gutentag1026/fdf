/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:55:58 by yhuang            #+#    #+#             */
/*   Updated: 2018/03/01 17:07:42 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*result;
	size_t		siz;
	int			begin;
	int			end;

	end = 0;
	begin = 0;
	if (s)
	{
		while (s[end] != '\0')
			end++;
		while (ft_isspace(s[--end]))
			;
		end++;
		while (ft_isspace(s[begin]) && s[begin] != '\0')
			begin++;
		siz = end > begin ? (end - begin) : 0;
		if (siz == 0)
			result = ft_memalloc(1);
		else
			result = ft_strsub(s, begin, siz);
		return (result);
	}
	return (NULL);
}
