/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:34:54 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 11:30:11 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//fill struct - initialize, store width & precision
//after filling, modify the struct
static void	store_wid(const char *format, int *i, t_printf *store, va_list ap)
{
	int tmp;

	if (format[*i] >= '0' && format[*i] <= '9')
	{
		store->min_w = ft_atoi(&format[*i]);
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
	if (format[*i] == '*')
	{
		tmp = va_arg(ap, int);
		if (tmp < 0)
		{
			store->min_w = -tmp;
			store->f_neg = 1;
		}
		else
			store->min_w = tmp;
		while (format[*i] == '*')
			(*i)++;
	}
}

static void	store_prec(const char *format, int *i, t_printf *store, va_list ap)
{
	while (format[*i] == '.')
		(*i)++;
	if ((format[*i] < '0' || format[*i] > '9') && format[*i] != '*')
	{
		store->prec = 0;
		return ;
	}
	if (format[*i] >= '0' && format[*i] <= '9')
	{
		store->prec = ft_atoi(&format[*i]);
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
	if (format[*i] == '*')
	{
		store->prec = va_arg(ap, int);
		while (format[*i] == '*')
			(*i)++;
	}
}

static void	store_modify(t_printf *store)
{
	if (store->conv && store->conv != 'd' && store->conv != 'i')
		store->f_sp = 0;
	if (store->conv != 'd' && store->conv != 'i' && store->conv != 'o'
			&& store->conv != 'u' && store->conv != 'x' &&
			store->conv != 'X' && store->conv != 's')
		store->prec = -1;
	if (store->prec >= 0 && store->conv != 's')
		store->f_zero = 0;
	if (store->f_neg)
		store->f_zero = 0;
	if (store->f_pos)
		store->f_sp = 0;
}

static void	ini_store(t_printf *store)
{
	store->f_hash = 0;
	store->f_zero = 0;
	store->f_neg = 0;
	store->f_pos = 0;
	store->f_sp = 0;
	store->res = 0;
	store->min_w = 0;
	store->prec = -1;//no precision specified
	store->mod = 0;
	store->conv = 0;
	store->str = NULL;
	store->str_sp1 = NULL;
	store->str_sign = 0;
	store->str_hash = NULL;
	store->str_zero = NULL;
	store->str_sp2 = NULL;
}

void		fill_store(const char *format, int *i, t_printf *store, va_list ap)
{
	int tmp;

	ini_store(store);
	while (format[*i] && format[*i] != '%')
	{
		if (ft_isflag(format[*i]))
			store_flag(format[*i], i, store);
		else if ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '*')
			store_wid(format, i, store, ap);
		else if (format[*i] == '.')
			store_prec(format, i, store, ap);
		else if ((tmp = ft_ismod(format, i)) != 0)
			store_mod(tmp, store);
		else
			break ;
	}
	if (format[*i])
		store_conv(format[*i], i, store);
	store_modify(store);
	store_str(ap, store);
}
