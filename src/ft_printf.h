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

typedef struct		s_params
{
	int 			width;
	int 			len;
	int 			precision;
	char 			flag[9];
	char 			type;
}					t_params;

int 	ft_printf(const char *format, ...);
void	ft_va_putchar(va_list ap, t_params *params);
void	ft_va_putstr(va_list ap, t_params *params);
void 	ft_va_putnbr(va_list ap, t_params *params);
void 	ft_va_putunbr(va_list ap, t_params *params);
void	ft_va_putoctal(va_list ap, t_params *params);
void	ft_va_puthex(va_list ap, t_params *params);
void	ft_va_l_puthex(va_list ap, t_params *params);
void	ft_va_putpointer(va_list ap, t_params *params);
void	ft_va_putfloat(va_list ap, t_params *params);

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_format_str(char *s, t_params *params);
void	print_percent(t_params *params);

/*Additional functions*/

char	*ft_itoa_base(int value, int base);
char	*ft_uitoa_base(unsigned int value, int base);
char	*ft_ll_itoa_base(long long value, int base);
int		count_digits(int value, int base);
int 	count_ll_digits(long long value, int base);
size_t	ft_strlen(const char *string);
char	*ft_strnew(size_t size);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strclr(char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);

/*Function array*/
void	fill_function_arr(void (*f[10])(va_list, t_params*));
int 	find_flag(char *flags, char c);
int		type_id(char c);
#endif
