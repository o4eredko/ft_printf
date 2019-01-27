/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:14:23 by yochered          #+#    #+#             */
/*   Updated: 2018/11/26 10:14:24 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include "libft.h"
# define FLAGS "+-0 #"
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define FL(c) (((c) == '+' || (c) == '-' || (c) == '0' || (c) == ' ' || (c) == '#') ? 1 : 0)
# define CL(c) (((c) == 'h' || (c) == 'l' || (c) == 'j' || (c) == 'L' || (c) == 'z') ? 1 : 0)
# define RED(string) "\x1b[31m" string "\x1b[0m"
# define BRED(string) "\x1b[1;31m" string "\x1b[0m"
# define GREEN(string) "\x1b[0;32m" string "\x1b[0m"
# define BGREEN(string) "\x1b[1;32m" string "\x1b[0m"
# define YELLOW(string) "\x1b[0;33m" string "\x1b[0m"
# define BYELLOW(string) "\x1b[01;33m" string "\x1b[0m"
# define BLUE(string) "\x1b[0;34m" string "\x1b[0m"
# define BBLUE(string) "\x1b[1;34m" string "\x1b[0m"
# define MAGENTA(string) "\x1b[0;35m" string "\x1b[0m"
# define BMAGENTA(string) "\x1b[1;35m" string "\x1b[0m"
# define CYAN(string) "\x1b[0;36m" string "\x1b[0m"
# define BCYAN(string) "\x1b[1;36m" string "\x1b[0m"

typedef	enum 	e_flags{
	plus = 1,
	minus = 2,
	zero = 4,
	space = 8,
	hash = 16,
	precision = 32,
	width = 64
}				t_flags;

typedef enum	e_convert
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z,
	L
}				t_convert;

typedef struct	s_fmt
{
	int			width;
	int			prec;
	int			flag;
	char		type;
	char		*str;
	char		buf[255];
	t_flags		f;
	t_convert	conv;
}				t_fmt;

void			handle_length(t_fmt *fmt);
void			handle_precision(t_fmt *fmt, va_list ap);
void			handle_width(t_fmt *fmt, va_list ap);
void			handle_flags(t_fmt *fmt);
int				ft_va_putchar(va_list ap, t_fmt *fmt);
int				ft_va_putstr(va_list ap, t_fmt *fmt);
int				ft_va_putnbr(va_list ap, t_fmt *fmt);
int				ft_va_putunbr(va_list ap, t_fmt *fmt);
int				ft_va_putoctal(va_list ap, t_fmt *fmt);
int				ft_va_puthex(va_list ap, t_fmt *fmt);
int				ft_va_putpointer(va_list ap, t_fmt *fmt);
int				ft_va_putfloat(va_list ap, t_fmt *fmt);
int				ft_va_putbinary(va_list ap, t_fmt *fmt);
int				ft_va_putnonprint(va_list ap, t_fmt *fmt);
void			print_padding(int size, char c);
int				ft_format_str(char *s, t_fmt *fmt);
int				print_percent(char c, t_fmt *fmt);
intmax_t		ft_power(intmax_t nb, int power);
int				allowed_s(char *format);
int				count_unsigned_digits(uintmax_t value, int base);
int				count_signed_digits(intmax_t value, int base);
void			uint_to_str(char *res, uintmax_t nbr,
		int base, t_fmt *fmt);
void			int_to_str(char *res, intmax_t nbr,
		int base, t_fmt *fmt);
char			*ft_strcp(char *dst, const char *src);
char			*ft_strjoin_free(char *s1, char *s2);
uintmax_t		convert_unsigned_arg(va_list ap, t_fmt *fmt);
void			init_fmt(t_fmt *fmt);
int				type_id(char c, t_fmt *fmt);

#endif
