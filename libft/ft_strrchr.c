/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:56:02 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:24:53 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const *last;

	last = 0;
	while (1)
	{
		if (*s == c)
			last = s;
		if (*s == '\0')
			break ;
		++s;
	}
	return ((char*)last);
}
