/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:58:29 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:23:33 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*buff;

	i = ft_strlen(s1) + 1;
	if (!(buff = (char*)malloc(i)))
		return (0);
	i = 0;
	while (s1[i])
	{
		buff[i] = s1[i];
		++i;
	}
	buff[i] = '\0';
	return (buff);
}
