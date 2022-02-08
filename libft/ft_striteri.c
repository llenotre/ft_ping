/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:54:17 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:23:46 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;

	if (s == 0 || f == 0)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		++i;
	}
}
