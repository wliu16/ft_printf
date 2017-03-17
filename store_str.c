/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:42:57 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 16:09:30 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//convert argument
static intmax_t		get_sig_int(va_list ap, t_printf *store)
{
	if (store->mod == 0)
		return (va_arg(ap, int));
	else if (store->mod == -1)
		return ((short)va_arg(ap, int));
	else if (store->mod == -2)
		return ((signed char)va_arg(ap, int));
	else if (store->mod == 1)
		return (va_arg(ap, long));
	else if (store->mod == 2)
		return (va_arg(ap, long long));
	else if (store->mod == 3)
		return (va_arg(ap, intmax_t));
	else if (store->mod == 4)
		return (va_arg(ap, ssize_t));
	else
		return (0);
}

static uintmax_t	get_uns_int(va_list ap, t_printf *store)
{
	if (store->mod == 0)
		return (va_arg(ap, unsigned int));
	else if (store->mod == -1)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (store->mod == -2)
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (store->mod == 1)
		return (va_arg(ap, unsigned long));
	else if (store->mod == 2)
		return (va_arg(ap, unsigned long long));
	else if (store->mod == 3)
		return (va_arg(ap, uintmax_t));
	else if (store->mod == 4)
		return (va_arg(ap, size_t));
	else
		return (0);
}

void				store_str(va_list ap, t_printf *store)
{
	if (!store->conv)
		return ;
	if (store->conv == 's' && store->mod > 0)
		str_wstr(va_arg(ap, wchar_t *), store);
	else if (store->conv == 's')
		str_str(va_arg(ap, char *), store);
	else if (store->conv == 'd' || store->conv == 'i')
		str_sig_int(get_sig_int(ap, store), store);
	else if (store->conv == 'o' || store->conv == 'u'
			|| store->conv == 'x' || store->conv == 'X')
		str_uns_int(get_uns_int(ap, store), store);
	else if (store->conv == 'c' && store->mod > 0)
		str_wchar(va_arg(ap, wint_t), store);
	else if (store->conv == 'c')
		str_char(va_arg(ap, int), store);
	else
		str_char(store->conv, store);
	add_zero(store);
	add_sp(store);
}
