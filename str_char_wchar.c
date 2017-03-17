/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_char_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:43:20 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 10:43:32 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <wchar.h>

//char, wchar
void	str_char(int ch, t_printf *store)
{
	if (ch == 0)
		store->str = ft_strnew(0);
	else
	{
		store->str = ft_strnew(1);
		store->str[0] = ch;
	}
	store->res += 1;
}

int		getsize_wchar(wint_t ch)
{
	if ((wchar_t)ch <= 0x7F)
		return (1);
	if ((wchar_t)ch <= 0x7FF)
		return (2);
	if ((wchar_t)ch <= 0xFFFF)
		return (3);
	else
		return (4);
}

void	str_wchar(wint_t ch, t_printf *store)
{
	int size;

	size = getsize_wchar(ch);
	store->str = ft_strnew(size);
	if ((wchar_t)ch <= 0x7F)
		store->str[0] = ch;
	else if ((wchar_t)ch <= 0x7FF)
	{
		store->str[0] = (ch >> 6) + 0xC0;
		store->str[1] = (ch & 0x3F) + 0x80;
	}
	else if ((wchar_t)ch <= 0xFFFF)
	{
		store->str[0] = (ch >> 12) + 0xE0;
		store->str[1] = ((ch >> 6) & 0x3F) + 0x80;
		store->str[2] = (ch & 0x3F) + 0x80;
	}
	else if ((wchar_t)ch <= 0x10FFFF)
	{
		store->str[0] = (ch >> 18) + 0xF0;
		store->str[1] = ((ch >> 12) & 0x3F) + 0x80;
		store->str[2] = ((ch >> 6) & 0x3F) + 0x80;
		store->str[3] = (ch & 0x3F) + 0x80;
	}
	store->res += size;
}
