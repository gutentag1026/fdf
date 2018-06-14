/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:47:40 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/26 17:17:01 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *listnew;

	if (!(listnew = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		listnew->content = NULL;
		listnew->content_size = 0;
	}
	else
	{
		listnew->content = ft_memalloc(content_size);
		if (listnew->content == NULL)
		{
			free(listnew);
			return (NULL);
		}
		ft_memcpy(listnew->content, content, content_size);
		listnew->content_size = content_size;
	}
	listnew->next = NULL;
	return (listnew);
}
