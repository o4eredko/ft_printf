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
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <time.h>
# define FLAGS "+-0 #"
# define ABS(x) (x < 0) ? -x : x
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

typedef struct		s_params
{
	int				width;
	int				precision;
	int				flag;
	enum {
		plus = 1,
		minus = 2,
		zero = 4,
		space = 8,
		hash = 16,
		precision = 32,
		width = 64
	}				e_flags;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z,
		L
	}				e_convert;
}					t_params;

int					ft_printf(const char *format, ...);
int					ft_va_putchar(va_list ap, t_params *params);
int					ft_va_putstr(va_list ap, t_params *params);
int					ft_va_putnbr(va_list ap, t_params *params);
int					ft_va_putunbr(va_list ap, t_params *params);
int					ft_va_putoctal(va_list ap, t_params *params);
int					ft_va_puthex(va_list ap, t_params *params);
int					ft_va_l_puthex(va_list ap, t_params *params);
int					ft_va_putpointer(va_list ap, t_params *params);
int					ft_va_putfloat(va_list ap, t_params *params);
int 				ft_va_putsnotation(va_list ap, t_params *params);
int					ft_va_putbinary(va_list ap, t_params *params);
int					ft_va_putnonprint(va_list ap, t_params *params);

void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnstr(char *str, int n);
void				print_padding(int size, char c);
int					ft_format_str(char *s, t_params *params);
int					print_percent(t_params *params);
intmax_t			ft_power(intmax_t nb, int power);

int					flag_list(char c);
int					convert_list(char c);

int					allowed_symbols(char *format);
int					count_unsigned_digits(uintmax_t value, int base);
int					count_signed_digits(intmax_t value, int base);
void				uint_to_str(char *res, uintmax_t nbr,
		int base, t_params *params);
void				int_to_str(char *res, intmax_t nbr,
		int base, t_params *params);

char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *string);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strclr(char *s);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*ft_strjoin(char *s1, char *s2);
void				*ft_memset(void *b, int c, size_t len);
void				ft_strrev(char *str, int len);
void				str_toupper(char *str);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
uintmax_t			convert_unsigned_arg(va_list ap, t_params *params);

void				fill_function_arr(int (**f)(va_list ap, t_params* params));
int					type_id(char c);

#endif
