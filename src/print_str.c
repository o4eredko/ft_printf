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

void	ft_putchar(char c, t_params *params)
{
	if (params && params->flag != '-' && params->width)
		while (params->width-- > 1)
			write(1, " ", 1);
	write(1, &c, 1);
	if (params && params->flag == '-' && params->width)
		while (params->width-- > 1)
			write(1, " ", 1);
}

void	ft_putstr(const char *s, t_params *params)
{
	size_t	len;

	len = ft_strlen(s);
	if (params->flag != '-' && params->width)
		while (params->width-- > len)
			ft_putchar(' ', NULL);
	while (*s)
	{
		ft_putchar(*s, NULL);
		s++;
	}
	if (params->flag == '-' && params->width)
		while (params->width-- > len)
			ft_putchar(' ', NULL);
}

void	ft_va_putchar(va_list ap, t_params *params)
{
	char c;

	c = va_arg(ap, int);
	ft_putchar(c, params);
}

void	ft_va_putstr(va_list ap, t_params *params)
{
	size_t	len;
	char 	*s;

	s = va_arg(ap, char*);
	ft_putstr(s, params);
}
