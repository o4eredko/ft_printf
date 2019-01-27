/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:14:10 by yochered          #+#    #+#             */
/*   Updated: 2018/11/26 10:14:13 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	fill_farr(int (**f)(va_list ap, t_fmt *fmt))
{
	f[0] = &ft_va_putchar;
	f[1] = &ft_va_putstr;
	f[2] = &ft_va_putnbr;
	f[3] = &ft_va_putunbr;
	f[4] = &ft_va_putoctal;
	f[5] = &ft_va_puthex;
	f[6] = &ft_va_putpointer;
	f[7] = &ft_va_putfloat;
	f[8] = &ft_va_putbinary;
	f[9] = &ft_va_putnonprint;
}

int		type_id(char c, t_fmt *fmt)
{
	char	*str;
	int		i;

	i = -1;
	if (c == 'D' || c == 'U' || c == 'O')
	{
		c -= 32;
		fmt->conv = l;
	}
	str = "csduoxpfbr";
	while (str[++i])
		if (c == str[i] || (c == 'i' && str[i] == 'd') ||
			(c == 'X' && str[i] == 'x') || (c == 'F' && str[i] == 'f'))
		{
			if (fmt)
				fmt->type = c;
			return (i);
		}
	return (-1);
}

static int	handle_expression(va_list ap, t_fmt *fmt)
{
	int ret;
	int (*f[10])(va_list, t_fmt*);

	fill_farr(f);
	ret = 0;
	fmt->str++;
	while (*(fmt->str) && allowed_s(fmt->str) &&
		type_id(*(fmt->str), fmt) == -1 && *(fmt->str) != '%')
	{
		if (FL(*(fmt->str)))
			handle_flags(fmt);
		else if (ft_isdigit(*(fmt->str)) || *(fmt->str) == '*')
			handle_width(fmt, ap);
		else if (*(fmt->str) == '.')
			handle_precision(fmt, ap);
		else if (CL(*(fmt->str)))
			handle_length(fmt);
	}
	if (*(fmt->str) && type_id(*(fmt->str), fmt) != -1)
		ret = f[type_id(*(fmt->str)++, fmt)](ap, fmt);
	else if (*(fmt->str) && *(fmt->str) == '%')
		ret = print_percent(*(fmt->str)++, fmt);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	char	*next;
	t_fmt	fmt;

	ret = 0;
	fmt.str = ft_strdup(format);
	va_start(ap, format);
	while (*(fmt.str))
	{
		init_fmt(&fmt);
		if (!(next = ft_strchr(fmt.str, '%')))
			next = ft_strchr(fmt.str, '\0');
		if (fmt.str != next)
		{
			ret += next - fmt.str;
			write(1, fmt.str, next - fmt.str);
			fmt.str += next - fmt.str;
		}
		else
			ret += handle_expression(ap, &fmt);
	}
	va_end(ap);
	return (ret);
}
