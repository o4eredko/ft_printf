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

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

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
