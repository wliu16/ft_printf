/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_int_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:31:08 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 16:54:34 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//for unsigned integer (%u %o %x %X)
static int	getsize_base(uintmax_t n, size_t base)
{
	int	size;

	size = 1;
	while (n >= base)
	{
		size++;
		n /= base;
	}
	return (size);
}

void		ft_oct(uintmax_t un, t_printf *store)
{
	int	size;

	if (store->f_hash)
	{
		store->str_hash = ft_strdup("0");
		store->res += 1;
	}
	if (un == 0 && (store->prec == 0 || store->f_hash))
		return ;
	size = getsize_base(un, 8);
	store->str = ft_strnew(size);
	store->res += size;
	while (--size >= 0)
	{
		store->str[size] = un % 8 + 48;
		un /= 8;
	}
}

void		ft_uns_dec(uintmax_t un, t_printf *store)
{
	int	size;

	if (un == 0 && store->prec == 0)
		return ;
	size = getsize_base(un, 10);
	store->str = ft_strnew(size);
	store->res += size;
	while (--size >= 0)
	{
		store->str[size] = un % 10 + 48;
		un /= 10;
	}
}

void		ft_hex_lo(uintmax_t un, t_printf *store)
{
	int	size;

	if (un == 0 && store->prec == 0)
		return ;
	if (un > 0 && store->f_hash && !store->str_hash)
	{
		store->str_hash = ft_strdup("0x");
		store->res += 2;
	}
	size = getsize_base(un, 16);
	store->str = ft_strnew(size);
	store->res += size;
	while (--size >= 0)
	{
		if (un % 16 < 10)
			store->str[size] = un % 16 + 48;
		else
			store->str[size] = un % 16 + 87;
		un /= 16;
	}
}

void		ft_hex_up(uintmax_t un, t_printf *store)
{
	int	size;

	if (un == 0 && store->prec == 0)
		return ;
	if (un > 0 && store->f_hash)
	{
		store->str_hash = ft_strdup("0X");
		store->res += 2;
	}
	size = getsize_base(un, 16);
	store->str = ft_strnew(size);
	store->res += size;
	while (--size >= 0)
	{
		if (un % 16 < 10)
			store->str[size] = un % 16 + 48;
		else
			store->str[size] = un % 16 + 55;
		un /= 16;
	}
}
