/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_uns_int2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:46:34 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 15:51:09 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//str for unsigned int
void	str_uns_int(uintmax_t un, t_printf *store)
{
	if (store->conv == 'o')
		ft_oct(un, store);
	else if (store->conv == 'u')
		ft_uns_dec(un, store);
	else if (store->conv == 'x')
		ft_hex_lo(un, store);
	else if (store->conv == 'X')
		ft_hex_up(un, store);
}
