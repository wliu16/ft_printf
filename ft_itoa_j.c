/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:55:48 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 15:53:01 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	getsize(intmax_t n)
{
	int	neg;
	int	res;

	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	else
		neg = 0;
	res = 1;
	while (n > 9)
	{
		res++;
		n /= 10;
	}
	return (res + neg);
}

char		*ft_itoa_j(intmax_t n)
{
	int		size;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n >= -9223372036854775807)
	{
		size = getsize(n);
		if (n < 0)
			n = -n;
		res = ft_strnew(size);
		if (!res)
			return (NULL);
		while (--size >= 0 && n > 0)
		{
			res[size] = n % 10 + '0';
			n /= 10;
		}
		if (size == 0)
			res[size] = '-';
		return (res);
	}
	else
		return (ft_strdup("-9223372036854775808"));
}
