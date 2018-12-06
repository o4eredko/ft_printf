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

int			handle_flags(char **format, t_params *params)
{
	char	*flags;
	int		i;

	params->flag = 0;
	params->e_flags = 0;
	flags = FLAGS;
	if (!allowed_symbols(*format))
		return (-1);
	while (flag_list(**format))
	{
		i = -1;
		while (flags[++i])
			if (flags[i] == **format)
				params->flag |= ft_power(2, i);
		(*format)++;
	}
	return (1);
}

int 		handle_width(char **format, t_params *params, va_list ap)
{
	if (!allowed_symbols(*format))
		return (-1);
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			params->width = va_arg(ap, int);
			params->flag |= width;
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			params->width = ft_atoi(*format);
			params->flag |= width;
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
	if (params->flag & width && params->width < 0)
	{
		params->flag |= minus;
		params->width = -params->width;
	}
	return (1);
}

int			handle_precision(char **format, t_params *params, va_list ap)
{
	if (!allowed_symbols(*format))
		return (-1);
	if (**format == '.' && *(*format + 1) == '*')
	{
		params->precision = va_arg(ap, int);
		params->flag |= params->precision >= 0 ? precision : 0;
		(*format) += 2;
	}
	else if (**format == '.' && ft_isdigit(*(*format + 1)))
	{
		(*format)++;
		params->precision = ft_atoi(*format);
		params->flag |= params->precision >= 0 ? precision : 0;
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '.' && !ft_isdigit(*(*format + 1)))
	{
		(*format)++;
		params->precision = 0;
		params->flag |= params->precision >= 0 ? precision : 0;
	}
	return (1);
}

int 		handle_length(char **format, t_params *params)
{
	params->e_convert = none;
	if (!allowed_symbols(*format))
		return (-1);
	if (**format == 'h' && *(*format + 1) != 'h')
		params->e_convert = h;
	else if (**format == 'h' && *(*format + 1) == 'h')
		params->e_convert = hh;
	else if (**format == 'l' && *(*format + 1) != 'l')
		params->e_convert = l;
	else if (**format == 'l' && *(*format + 1) == 'l')
		params->e_convert = ll;
	else if (**format == 'j')
		params->e_convert = j;
	else if (**format == 'z')
		params->e_convert = z;
	else if (**format == 'L')
		params->e_convert = L;
	while (type_id(**format) == -1 && **format != '%')
		(*format)++;
	return (1);
}

int			handle_expression(va_list ap, const char **format)
{
	t_params	params;
	int 		ret;
	int 		index;
	int			(*f[10])(va_list, t_params*);

	ret = 0;
	fill_function_arr(f);
	(*format)++;
	if (!**format)
		return (0);
	if (handle_flags((char**)format, &params) == -1)
		return (0);
	if (handle_width((char**)format, &params, ap) == -1)
		return (0);
	if (handle_precision((char**)format, &params, ap) == -1)
		return (0);
	if (handle_length((char**)format, &params) == -1)
		return (0);
	if ((index = type_id(**format)) == -1 && **format != '%')
		exit(0);
	ret += **format == '%' ? print_percent(&params) : f[index](ap, &params);
	(*format)++;
	return (ret);
}

int 		ft_printf(const char *format, ...)
{
	va_list		ap;
	int 		ret;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ret += handle_expression(ap, &format);
		else
		{
			ft_putchar(*format);
			format++;
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}
