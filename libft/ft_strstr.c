/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:56:18 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:25:00 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		i = 0;
		while (1)
		{
			if (needle[i] == '\0')
				return ((char*)haystack);
			if (haystack[i] != needle[i])
				break ;
			++i;
		}
		++haystack;
	}
	return (0);
}
