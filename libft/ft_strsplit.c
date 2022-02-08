/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:57:44 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:24:56 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_skip(char const **s, const char c)
{
	while (**s && **s == c)
		++(*s);
}

static size_t	ft_split_count(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s)
	{
		ft_skip(&s, c);
		if (!(*s))
			break ;
		++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

static size_t	ft_split_size(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**arr;
	size_t	i;
	size_t	len;

	if (s == 0)
		return (0);
	count = ft_split_count(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (count + 1))))
		return (0);
	i = 0;
	while (*s && i < count)
	{
		ft_skip(&s, c);
		len = ft_split_size(s, c);
		if (!(arr[i] = (char*)malloc(len + 1)))
			return (0);
		ft_strncpy(arr[i], s, len);
		arr[i][len] = '\0';
		s += len;
		++i;
	}
	arr[i] = 0;
	return (arr);
}
