/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:31:36 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:22:19 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int n, unsigned int factor)
{
	unsigned int i;

	if (factor == 0)
		return (1);
	i = 0;
	while (i < factor)
	{
		n *= n;
		++i;
	}
	return (n);
}
