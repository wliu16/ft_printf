/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_sp_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:36:07 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 11:41:23 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*sp_str(int len)
{
	char	*res;
	int		i;

	res = ft_strnew(len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = ' ';
		i++;
	}
	return (res);
}

static char	*zero_str(int len)
{
	char	*res;
	int		i;

	res = ft_strnew(len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = '0';
		i++;
	}
	return (res);
}

void		add_sp(t_printf *store)
{
	int	tmp;
	int	sp;

	sp = 0;
	if (store->f_sp)
	{
		store->str_sp1 = ft_strdup(" ");
		store->res += 1;
		sp = 1;
	}
	if ((tmp = store->min_w - store->res) > 0)
	{
		if (store->f_neg)
			store->str_sp2 = sp_str(tmp);
		else
		{
			if (store->str_sp1)
				free(store->str_sp1);
			store->str_sp1 = sp_str(sp + tmp);
		}
		store->res += tmp;
	}
}

void		add_zero(t_printf *store)
{
	int	tmp;
	int	str_size;

	if (store->str)
		str_size = ft_strlen(store->str);
	else
		str_size = 0;
	if (store->conv == 'o' && store->f_hash)
		str_size += 1;
	if (store->conv)
	{
		if ((store->f_zero &&
					(tmp = store->min_w - store->res - store->f_sp) > 0))
		{
			store->str_zero = zero_str(tmp);
			store->res += tmp;
		}
		else if ((store->conv == 'o' || store->conv == 'u' || store->conv == 'x'
					|| store->conv == 'd' || store->conv == 'i' ||
					store->conv == 'X') && (tmp = store->prec - str_size) > 0)
		{
			store->str_zero = zero_str(tmp);
			store->res += tmp;
		}
	}
}
