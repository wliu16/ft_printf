/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_str_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:45:36 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 10:49:23 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//str, wstr
void		str_str(char *str, t_printf *store)
{
	int len;

	if (str == 0)
		if (store->prec >= 0 && store->prec < 6)
		{
			store->str = ft_strnew(store->prec);
			ft_strncpy(store->str, "(null)", store->prec);
		}
		else
			store->str = ft_strdup("(null)");
	else
	{
		len = ft_strlen(str);
		if (store->prec >= 0 && store->prec < len)
		{
			store->str = ft_strnew(store->prec);
			ft_strncpy(store->str, str, store->prec);
		}
		else
			store->str = ft_strdup(str);
	}
	store->res += ft_strlen(store->str);
}

static void	fill_wstr(wchar_t wch, char *res, int *i)
{
	if (wch <= 0x7F)
		res[(*i)++] = wch;
	else if (wch <= 0x7FF)
	{
		res[(*i)++] = (wch >> 6) + 0xC0;
		res[(*i)++] = (wch & 0x3F) + 0x80;
	}
	else if (wch <= 0xFFFF)
	{
		res[(*i)++] = (wch >> 12) + 0xE0;
		res[(*i)++] = ((wch >> 6) & 0x3F) + 0x80;
		res[(*i)++] = (wch & 0x3F) + 0x80;
	}
	else if (wch <= 0x10FFFF)
	{
		res[(*i)++] = (wch >> 18) + 0xF0;
		res[(*i)++] = ((wch >> 12) & 0x3F) + 0x80;
		res[(*i)++] = ((wch >> 6) & 0x3F) + 0x80;
		res[(*i)++] = (wch & 0x3F) + 0x80;
	}
}

static char	*wstr_to_str(wchar_t *wstr, int prec)
{
	int		i;
	int		size;
	char	*res;

	i = 0;
	size = 0;
	while (wstr[i] && (prec == -1 || size + getsize_wchar(wstr[i]) <= prec))
	{
		size += getsize_wchar(wstr[i]);
		i++;
	}
	res = ft_strnew(size);
	i = 0;
	while (*wstr && i < size)
	{
		fill_wstr(*wstr, res, &i);
		wstr++;
	}
	return (res);
}

void		str_wstr(wchar_t *wstr, t_printf *store)
{
	int		len;
	int		prec;
	char	*str;

	if (wstr == 0)
		str = ft_strdup("(null)");
	else
		str = wstr_to_str(wstr, store->prec);
	len = ft_strlen(str);
	prec = store->prec;
	if (prec > 0 && prec < len)
	{
		store->str = ft_strnew(prec);
		ft_strncpy(store->str, str, prec);
		free(str);
		store->res += prec;
	}
	else
	{
		store->str = str;
		store->res += len;
	}
}
