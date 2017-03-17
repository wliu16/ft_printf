/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_sig_int2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:44:20 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 15:51:32 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//%d, %i
void	str_sig_int(intmax_t n, t_printf *store)
{
	char	*num;

	if (n < 0)
		store->str_sign = '-';
	else if (store->f_pos)
		store->str_sign = '+';
	if (store->str_sign)
		store->res += 1;
	if (n == 0 && store->prec == 0)
		return ;
	num = ft_itoa_j(n);
	if (n < 0)
	{
		store->str = ft_strdup(&num[1]);
		free(num);
		store->f_sp = 0;
	}
	else
		store->str = num;
	store->res += ft_strlen(store->str);
}
