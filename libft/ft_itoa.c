/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:02:18 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:21:08 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		return ((n > 9 ? ft_intlen(n / 10) + 1 : 1) + 1);
	}
	else
		return (n > 9 ? ft_intlen(n / 10) + 1 : 1);
}

static void		ft_itoa_fill(int n, char *buff, size_t len)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		buff[0] = '-';
		n = -n;
	}
	while (i < len && n > 0)
	{
		buff[len - i - 1] = '0' + (n % 10);
		n /= 10;
		++i;
	}
	buff[len] = '\0';
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*buff;

	len = ft_intlen(n);
	if (!(buff = (char*)ft_memalloc(len + 1)))
		return (0);
	if (n == 0)
		ft_strcpy(buff, "0");
	if (n == -2147483648)
		ft_strcpy(buff, "-2147483648");
	else
		ft_itoa_fill(n, buff, len);
	return (buff);
}
