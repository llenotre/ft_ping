/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:33:53 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:25:04 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *buff;

	if (s == 0)
		return (0);
	if (!(buff = (char*)malloc(len + 1)))
		return (0);
	ft_strncpy(buff, s + start, len);
	buff[len] = '\0';
	return (buff);
}
