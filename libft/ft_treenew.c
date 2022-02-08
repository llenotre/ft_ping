/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:00:37 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:25:37 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_treenew(const void *content, size_t content_size)
{
	t_tree *tree;

	if (!(tree = malloc(sizeof(t_tree))))
		return (0);
	if (!(tree->content = malloc(content_size)))
		return (0);
	ft_memcpy(tree->content, content, content_size);
	tree->content_size = content_size;
	tree->left = 0;
	tree->right = 0;
	return (tree);
}
