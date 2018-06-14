/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 00:32:30 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/25 03:23:55 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*word_count(char const *s, char c, unsigned *i)
{
	unsigned	j;
	unsigned	start;
	char		*word;

	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	start = *i;
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	word = ft_strnew(*i - start);
	if (!word)
		return (NULL);
	j = 0;
	while (start < *i)
	{
		word[j] = s[start];
		start++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void		word_check(char const *s, char c, unsigned *i, unsigned *w)
{
	while (s[*i] != '\0')
	{
		if (s[*i] != c && (s[*i + 1] == c || s[*i + 1] == '\0'))
			(*w)++;
		(*i)++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned	i;
	unsigned	j;
	unsigned	words;
	char		**ret;

	i = 0;
	words = 0;
	if (!s)
		return (NULL);
	word_check(s, c, &i, &words);
	i = 0;
	j = 0;
	ret = (char**)malloc(sizeof(char*) * (words + 1));
	if (!ret)
		return (NULL);
	while (i < words)
	{
		ret[i] = word_count(s, c, &j);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
