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

char	*add_format(char *str, t_params *params)
{
	char *res;

	res = ft_strnew(ft_strlen(str) + params->type == 'o' ? 1 : 2);
	if (params->type == 'o')
	{
		ft_strcpy(res, "0");
		ft_strcpy(res + 1, str);
	}
	else if (params->type == 'x' || params->type == 'X')
	{
		ft_strcpy(res, params->type == 'x' ? "0x" : "0X");
		ft_strcpy(res + 2, str);
	}
	free(str);
	return (res);
}

void	print_padding(int size, t_params *params)
{
	while (size-- > 0)
	{
		ft_putchar(find_flag(params->flag, '0')
		&& !find_flag(params->flag, '-') ? '0' : ' ');
		params->len++;
	}
}

void	print_percent(t_params *params)
{
	if (!find_flag(params->flag, '-') && params->width)
		print_padding(params->width - 1, params);
	ft_putchar('%');
	params->len++;
	if (find_flag(params->flag, '-') && params->width)
		print_padding(params->width - 1, params);
}

void	ft_format_str(char *s, t_params *params)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = params->width - len > 0 ? ft_strnew((size_t)params->width - len) : NULL;
	if (find_flag(params->flag, '#') || find_flag(params->flag, '0'))
		s = add_format(s, params);
	len = ft_strlen(s);
	if (str && !find_flag(params->flag, '0'))
	{
		ft_memset(str, ' ', (size_t)params->width - len);
		s = find_flag(params->flag, '-') ? ft_strjoin(s, str) : ft_strjoin(str, s);
	}
	ft_putstr(s);
	params->len = (int)ft_strlen(s);
	free(s);
}

void	ft_va_putchar(va_list ap, t_params *params)
{
	char c;

	c = (char)va_arg(ap, int);
	if (!find_flag(params->flag, '-') && params->width)
		print_padding(params->width - 1, params);
	ft_putchar(c);
	params->len++;
	if (find_flag(params->flag, '-') && params->width)
		print_padding(params->width - 1, params);
}

void	ft_va_putstr(va_list ap, t_params *params)
{
	char 	*s;

	s = va_arg(ap, char*);
	ft_format_str(s, params);
}
