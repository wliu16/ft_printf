/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:24:50 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 11:34:06 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isconv(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_isflag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_ismod(const char *format, int *i)
{
	if (format[*i] == 'l')
	{
		if (format[++(*i)] == 'l' && ++(*i))
			return (2);
		else
			return (1);
	}
	else if (format[*i] == 'h')
	{
		if (format[++(*i)] == 'h' && ++(*i))
			return (-2);
		else
			return (-1);
	}
	else if (format[*i] == 'j' && ++(*i))
		return (3);
	else if (format[*i] == 'z' && ++(*i))
		return (4);
	else
		return (0);
}
