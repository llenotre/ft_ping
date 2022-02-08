/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:01:22 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:25:28 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treedel(t_tree **tree, void (*del)(void*, size_t))
{
	t_tree *left;
	t_tree *right;

	left = (*tree)->left;
	right = (*tree)->right;
	ft_treedelone(tree, del);
	if (left != 0)
		ft_treedel(&left, del);
	if (right != 0)
		ft_treedel(&right, del);
}
