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
	|| (**format == 'l' && *(*format + 1) == 'l'));
}

void		handle_flag(const char **format, t_params *params)
{
	if ((**format == 'h' && *(*format + 1) == 'h')
	|| (**format == 'l' && *(*format + 1) == 'l'))
	{
		params->flag = (**format == 'h') ? 'c' : 'i';
		(*format) += 2;
	}
	else
	{
		params->flag = **format;
		(*format)++;
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

void		handle_expression(va_list ap, const char **format)
{
	t_params	params;
	void		(*f[10])(va_list, t_params*);

	fill_function_arr(f);
	(*format)++;
	if (flag_list(format))
		handle_flag(format, &params);
	handle_width(format, &params);
	if (type_id(**format) != -1 || **format == '%')
	{
		if (**format == '%')
			ft_putchar(**format, &params);
		else
			f[type_id(**format)](ap, &params);
		(*format)++;
	}
}

int 		ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			handle_expression(ap, &format);
		else
		{
			ft_putchar(*format, NULL);
			format++;
		}
	}
	va_end(ap);

	/*Return value has to be modified*/
	return (1);
}
