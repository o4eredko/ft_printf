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
# define FLAGS "+-0 #"

typedef struct		s_params
{
	int				width;
	int				precision;
	int 			flag;
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
int					ft_va_putbinary(va_list ap, t_params *params);
int					ft_va_putnonprint(va_list ap, t_params *params);

void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnstr(char *str, int n);
int					ft_format_str(char *s, t_params *params);
int					print_percent(t_params *params);
intmax_t 			ft_power(intmax_t nb, int power);
/*Additional functions*/
int				 	flag_list(char c);
int				 	convert_list(char c);

int 				allowed_symbols(char *format);
int 				count_unsigned_digits(uintmax_t value, int base);
int			 		count_signed_digits(intmax_t value, int base);
void 				uint_to_str(char *res, uintmax_t nbr, int base, t_params *params);
void 				int_to_str(char *res, intmax_t nbr, int base, t_params *params);

char				*ft_strdup(const char *s1);
char				*ft_itoa_base(intmax_t value, int base);
char				*ft_uitoa_base(unsigned int value, int base);
char				*ft_ll_itoa_base(long long value, int base);
int					count_digits(int value, int base);
int 				count_ll_digits(long long value, int base);
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

/*Function array*/
void				fill_function_arr(int (*f[10])(va_list, t_params*));
int 				find_flag(char *flags, char c);
int					type_id(char c);
#endif
