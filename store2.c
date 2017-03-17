/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:41:03 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 16:51:05 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//fill struct - modifier, flag, conversion
void	store_mod(char ch, t_printf *store)
{
	if (store->mod == 0 || store->mod < ch)
		store->mod = ch;
}

void	store_flag(char ch, int *i, t_printf *store)
{
	(*i)++;
	if (ch == '#')
		store->f_hash = 1;
	else if (ch == '0')
		store->f_zero = 1;
	else if (ch == '-')
		store->f_neg = 1;
	else if (ch == '+')
		store->f_pos = 1;
	else
		store->f_sp = 1;
}

void	store_conv(char ch, int *i, t_printf *store)
{
	(*i)++;
	if (ch == 'D' || ch == 'O' || ch == 'U' || ch == 'S' || ch == 'C')
	{
		store->conv = ch + 32;
		store->mod = 1;
	}
	else if (ch == 'p')
	{
		store->conv = 'x';
		store->mod = 1;
		store->f_hash = 1;
		store->str_hash = ft_strdup("0x");
		store->res += 2;
	}
	else
		store->conv = ch;
}
