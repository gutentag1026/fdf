/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 23:23:52 by yhuang            #+#    #+#             */
/*   Updated: 2018/04/02 21:15:43 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ft_strjoin joins strings of s1 and s2 by malloc s1 + s2 + 1 length's memory and
copies everything to allocated memories s3 including the NULL.
*/

char				*ft_strjoin_r(char *s1, char *s2) 
{
	char			*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (tmp);
}

/* ft_strnew(4) gives you a fresh string including null charaters like 00000, ft_strnew(0) gives you 0, 
memalloc(1) gives you 0 without null. This function copies everything passed in to newly allocated str[];
like abcdefg\n */
char				*read_file(char *store)
{
	char			*str;
	size_t			len;
	size_t			i;

	len = 0;
	while (store[len] != '\n')
		len++;
	str = ft_memalloc(len + 1);
	i = 0;
	while (i < len)
	{
		str[i] = store[i];
		i++;
	}
	return (str);
}

/* this function copies everything after a line 
for instance, abcd\nefg  it copies efg0 . But what it actually does is just to copy a null character after a line,
so tht the next time get_next_line is called, ft_memalloc is no longer empty.
*/

char				*copy_after_line(char *tmp)
{
	char *str;

	str = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	return (str);
}
/* The value of ulimit -n is 4864. 

ft_strjoin_r get rid of the null characters between strings

static char *store[FD_MAX] keeps tracks of characters read through last call to get_next_line, so it doesn't 
lose the previous characters if there was no new line.so store[fd] is itself instead of ft_memalloc(1); 

ft_strlen(store[fd]) == 0 indicates the end of fd.
*line gets overwritten each time we call get_next_line
*/
int					get_next_line(const int fd, char **line)
{
	char			*buf;
	static char		*store[FD_MAX];
	int				res;

	if (fd < 0 || fd >= FD_MAX || BUFF_SIZE < 1 || !line) 
		return (-1);
	buf = ft_memalloc(BUFF_SIZE + 1);
	if ((res = (read(fd, buf, BUFF_SIZE))) == -1)
	{
		free(buf);
		return (-1);
	}
	store[fd] = !store[fd] ? ft_memalloc(1) : store[fd];
	store[fd] = ft_strjoin_r(store[fd], buf);
	if (!ft_strlen(store[fd]))
		return (0);
	if (ft_strchr(store[fd], '\n') && (*line = read_file(store[fd])))
		store[fd] = copy_after_line(store[fd]);
	else if (!res && ft_strlen(store[fd]) && (*line = ft_strdup(store[fd])))
		ft_strdel(&store[fd]);
	else
		return (get_next_line(fd, line));
	return (1);
}
