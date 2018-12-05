/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:08:38 by yochered          #+#    #+#             */
/*   Updated: 2018/11/29 10:08:39 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnstr(char *str, int n)
{
	while (*str && n--)
	{
		ft_putchar(*str);
		str++;
	}
}

void	print_padding(int size, char c)
{
	while (size-- > 0)
		ft_putchar(c);
}

int		print_percent(t_params *params)
{
	int len;

	len = 1;
	if (params->flag & width)
		len = params->width > len ? params->width : len;
	if (params->flag & width && !(params->flag & minus))
		print_padding(params->width - 1, params->flag & zero ? '0' : ' ');
	ft_putchar('%');
	if (params->flag & width && params->flag & minus)
		print_padding(params->width - 1, ' ');
	return (len);
}

int		ft_format_str(char *s, t_params *params)
{
	int len;

	len = (int)ft_strlen(s);
	if (params->flag & width)
		len = params->width > len ? params->width : len;
	if (params->flag & width && !(params->flag & minus) && (!(params->flag & zero) || params->flag & precision))
		print_padding(params->width - (int)ft_strlen(s), ' ');
	if (params->flag & width && !(params->flag & minus) && params->flag & zero && !(params->flag & precision))
	{
		if (params->flag & hash || *s == '+' || *s == '-' || *s == ' ')
		{
			ft_putnstr(s, *(s + 1) == 'x' || *(s + 1) == 'X' ? 2 : 1);
			params->width -= *(s + 1) == 'x' || *(s + 1) == 'X' ? 2 : 1;
			s += *(s + 1) == 'x' || *(s + 1) == 'X' ? 2 : 1;
		}
		print_padding(params->width - (int)ft_strlen(s), '0');
	}
	ft_putstr(s);
	if (params->flag & width && params->flag & minus)
		print_padding(params->width - (int)ft_strlen(s), ' ');
	return (len);
}

int		ft_va_putchar(va_list ap, t_params *params)
{
	int 	len;
	char	c;

	c = (char)va_arg(ap, int);
	len = 1;
	if (params->flag & width)
		len = params->width > len ? params->width : len;
	if (params->flag & width && !(params->flag & minus))
		print_padding(params->width - 1, params->flag & zero ? '0' : ' ');
	ft_putchar(c);
	if (params->flag & width && params->flag & minus)
		print_padding(params->width - 1, ' ');
	return (len);
}

int		ft_va_putstr(va_list ap, t_params *params)
{
	char 	*s;

	s = va_arg(ap, char*);
	if (!s)
	{
		s = ft_strnew(params->flag & precision ? params->precision : 6);
		if (params->flag & width && params->flag & zero && params->flag & precision)
		{
			ft_memset(s, '0', (size_t)params->precision);
			ft_strcpy(s + params->precision - 1, "(null)");
		}
		else
			ft_strcpy(s, "(null)");
		if (!(params->flag & width))
			s[params->flag & precision ? params->precision : 6] = '\0';
		else
			s[params->width > 6 ? params->width - 1 : 6] = '\0';
	}
	else if (params->flag & precision && params->precision < (int)ft_strlen(s))
		s = ft_strsub(s, 0, (size_t)params->precision);
	return (ft_format_str(s, params));
}
