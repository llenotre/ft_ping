/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:54:39 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:24:09 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	if (s == 0)
		return (0);
	if (!(str = ft_strdup(s)))
		return (0);
	i = 0;
	while (str[i])
	{
		str[i] = f(str[i]);
		++i;
	}
	return (str);
}
