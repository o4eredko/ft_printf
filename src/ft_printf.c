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

#include "ft_printf.h"

int 		flag_list(const char **format)
{
	return  (**format == '#' || **format == '0' ||  **format == '-'
		|| **format == '+' || **format == ' ' || **format == 'h'
		|| (**format == 'h' && *(*format + 1) == 'h') || **format == 'l'
		|| (**format == 'l' && *(*format + 1) == 'l') || **format == 'z');
}

int 		find_flag(char *flags, char c)
{
	while (*flags)
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

void		handle_flag(const char **format, t_params *params)
{
	int i;

	i = -1;
	ft_strclr(params->flag);
	while (++i < 9 && flag_list(format))
	{
		if ((**format == 'h' && *(*format + 1) == 'h')
			|| (**format == 'l' && *(*format + 1) == 'l'))
		{
			params->flag[i] = (**format == 'h') ? 'c' : 'i';
			(*format) += 2;
		}
		else
		{
			params->flag[i] = **format;
			(*format)++;
		}
	}
}

void		handle_width(const char **format, t_params *params)
{
	if (ft_isdigit(**format))
		params->width = ft_atoi(*format);
	else
		params->width = 0;
	while (**format && ft_isdigit(**format))
		(*format)++;
}

void		handle_precision(const char **format, t_params *params)
{
	(*format)++;
	params->precision = ft_atoi(*format);
	(*format) += count_digits(params->precision, 10);
}

int			handle_expression(va_list ap, const char **format)
{
	t_params	params;
	void		(*f[10])(va_list, t_params*);

	params.precision = 0;
	params.len = 0;
	fill_function_arr(f);
	(*format)++;
	handle_flag(format, &params);
	handle_width(format, &params);
	if (**format == '.')
		handle_precision(format, &params);
	if (**format == '%')
		print_percent(&params);
	if (type_id(**format) != -1)
	{
		params.type = **format;
		f[type_id(**format)](ap, &params);
		(*format)++;
	}
	return (params.len);
}

int 		ft_printf(const char *format, ...)
{
	va_list		ap;
	int 		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			len += handle_expression(ap, &format);
		else
		{
			ft_putchar(*format);
			format++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
