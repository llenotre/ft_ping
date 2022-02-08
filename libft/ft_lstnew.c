/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:17:37 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:21:31 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content && content_size > 0)
	{
		if (!(list->content = malloc(content_size)))
			return (0);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	else
	{
		list->content = 0;
		list->content_size = 0;
	}
	list->next = 0;
	return (list);
}
