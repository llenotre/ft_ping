/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:56:36 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:24:50 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	while (*haystack && i < len)
	{
		j = 0;
		while (needle[j])
		{
			if (haystack[j] == '\0' || i + j >= len)
				return (0);
			if (haystack[j] != needle[j])
				break ;
			++j;
		}
		if (needle[j] == '\0')
			return ((char*)haystack);
		++haystack;
		++i;
	}
	return (0);
}
