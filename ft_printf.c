/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:36:26 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 15:29:35 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	output_free(char *str)
{
	if (str)
	{
		ft_putstr(str);
		free(str);
	}
}

static int	print_store(t_printf *store)
{
	int res;

	output_free(store->str_sp1);
	if (store->str_sign)
		ft_putchar(store->str_sign);
	output_free(store->str_hash);
	output_free(store->str_zero);
	if (store->conv == 'c' && store->str && *store->str == 0)
	{
		ft_putchar(0);
		free(store->str);
	}
	else
		output_free(store->str);
	output_free(store->str_sp2);
	res = store->res;
	free(store);
	return (res);
}

static int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_printf	*store;
	va_list		ap;
	int			res;
	int			i;

	i = 0;
	res = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[++i])
				break ;
			store = (t_printf *)malloc(sizeof(t_printf));
			if (!store)
				break ;
			fill_store(format, &i, store, ap);
			res += print_store(store);
		}
		else
			res += print_char(format[i++]);
	}
	va_end(ap);
	return (res);
}
