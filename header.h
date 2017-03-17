/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:31:50 by wliu              #+#    #+#             */
/*   Updated: 2017/01/23 15:54:46 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdbool.h>

typedef struct	s_printf
{
	bool	f_hash;
	bool	f_zero;
	bool	f_neg;
	bool	f_pos;
	bool	f_sp;
	int		min_w;//minimum width
	int		prec;//precision
	int8_t	mod;//modifier
	char	conv;//conversion
	int		res;//return value
	char	*str;//converted arg
	char	*str_sp1;//space before str
	char	str_sign;//negative int or flag +
	char	*str_hash;//flag #
	char	*str_zero;//zero padding
	char	*str_sp2;//space after str
}				t_printf;

int				ft_printf(const char *format, ...);
void			fill_store(const char *f, int *i, t_printf *s, va_list ap);
void			store_mod(char ch, t_printf *store);
void			store_flag(char ch, int *i, t_printf *store);
void			store_conv(char ch, int *i, t_printf *store);
void			store_str(va_list ap, t_printf *store);
void			add_zero(t_printf *store);
void			add_sp(t_printf *store);
void			str_char(int ch, t_printf *store);
int				getsize_wchar(wint_t ch);
void			str_wchar(wint_t ch, t_printf *store);
void			str_str(char *str, t_printf *store);
void			str_wstr(wchar_t *wstr, t_printf *store);
int				ft_isflag(char c);
int				ft_isconv(char c);
int				ft_ismod(const char *format, int *i);
void			ft_putchar(char c);
void			ft_putstr(char *str);
size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strdup(const char *str);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_atoi(const char *str);
char			*ft_itoa_j(intmax_t n);
void			str_sig_int(intmax_t n, t_printf *store);
void			str_uns_int(uintmax_t un, t_printf *store);
void			ft_uns_dec(uintmax_t n, t_printf *store);
void			ft_oct(uintmax_t n, t_printf *store);
void			ft_hex_lo(uintmax_t n, t_printf *store);
void			ft_hex_up(uintmax_t n, t_printf *store);

#endif
