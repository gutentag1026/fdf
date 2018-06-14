/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:17:26 by yhuang            #+#    #+#             */
/*   Updated: 2018/02/26 19:18:23 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *sort;

	if (lst)
	{
		sort = f(lst);
		sort->next = ft_lstmap(lst->next, f);
		return (sort);
	}
	return (NULL);
}
