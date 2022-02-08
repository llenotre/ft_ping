/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:24:16 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:21:27 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	void	*next;
	t_list	*list;

	next = lst->next;
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (0);
	ft_memcpy(list, f(lst), sizeof(t_list));
	if (next != 0)
		list->next = ft_lstmap(next, f);
	return (list);
}
