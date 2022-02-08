/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:50:44 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:24:17 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	size_t len1;
	size_t len2;
	size_t i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	while (i < len2 && i < len)
	{
		s1[len1 + i] = s2[i];
		++i;
	}
	s1[len1 + i] = '\0';
	return (s1);
}
