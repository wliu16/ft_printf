/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:18:10 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 12:22:12 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ismin(const char *str, const char *min)
{
	while (*min)
	{
		if (*str != *min)
			return (0);
		str++;
		min++;
	}
	if (*str >= '0' && *str <= '9')
		return (0);
	else
		return (1);
}

int			ft_atoi(const char *str)
{
	int	res;
	int	sign;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	if (ismin(str, "-2147483648"))
		return (-2147483648);
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}
