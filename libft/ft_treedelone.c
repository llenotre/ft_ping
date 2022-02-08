/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:00:58 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:25:33 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treedelone(t_tree **tree, void (*del)(void*, size_t))
{
	del((*tree)->content, (*tree)->content_size);
	free((void*)*tree);
	*tree = 0;
}
