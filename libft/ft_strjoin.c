/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:52:56 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:23:50 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*buff;

	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(buff = (char*)malloc(len1 + len2 + 1)))
		return (0);
	ft_strcpy(buff, s1);
	ft_strcpy(buff + len1, s2);
	buff[len1 + len2] = '\0';
	return (buff);
}
