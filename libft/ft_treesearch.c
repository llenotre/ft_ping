/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treesearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:01:44 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:25:41 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_treesearch(t_tree *tree, t_tree_side (*f)(void*, size_t))
{
	t_tree_side side;

	if (!tree)
		return (0);
	side = f(tree->content, tree->content_size);
	if (side == LEFT)
		return (ft_treesearch(tree->left, f));
	else if (side == RIGHT)
		return (ft_treesearch(tree->right, f));
	else
		return (tree);
}
