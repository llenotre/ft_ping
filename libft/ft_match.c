/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:00:04 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:21:35 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_match(const char *str, const char *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');
	while (*pattern == '*' && *(pattern + 1) == '*')
		++pattern;
	if (*str == '\0')
		return (*pattern == '*' && *(pattern + 1) == '\0');
	if (*pattern == '*')
		return (ft_match(str, pattern + 1) || ft_match(str + 1, pattern));
	if (*str == *pattern)
		return (ft_match(str + 1, pattern + 1));
	return (0);
}
