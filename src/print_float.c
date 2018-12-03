/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:03:45 by yochered          #+#    #+#             */
/*   Updated: 2018/11/25 18:03:46 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long ft_power(long long nb, int power)
{
	unsigned long long	res;

	res = 1;
	if (power <= 0)
		return (1);
	while (power--)
		res *= nb;
	return (res);
}

void		ft_strrev(char *str, int len)
{
	char	c;
	int 	i;

	i = -1;
	while (++i < --len)
	{
		c = str[i];
		str[i] = str[len];
		str[len] = c;
	}
}

int		ft_int_to_str(long long nbr, char *res, int precision)
{
	int i;

	i = 0;
	while (nbr)
	{
		res[i++] = (nbr < 0 ? -(nbr % 10) : nbr % 10) + '0';
		nbr /= 10;
	}
	while (i < precision)
		res[i++] = '0';
	ft_strrev(res, i);
	return (i);
}

void		ft_dtoa(long double nbr, char *res, int precision)
{
	long long 	i_part;
	long double	f_part;
	long long	i;

	i_part = (long long)nbr;
	f_part = nbr - (long double)i_part;
	i = ft_int_to_str(i_part, res, 1);
	if (precision)
	{
		res[i] = '.';
		f_part *= ft_power(10, precision);
		if ((int)((f_part - (long long)f_part) * 10) >= 5)
			f_part++;
		ft_int_to_str((long long)f_part, &res[i + 1], precision);
	}
}

void		ft_va_putfloat(va_list ap, t_params *params)
{
	long double	nbr;
	char 		*res;

	if (find_flag(params->flag, 'L'))
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	res = ft_strnew((unsigned int)(count_ll_digits((long long)nbr, 10)
			+ 1 + (params->precision ? params->precision : 6)));
	if (nbr < 0)
		*res++ = '-';
	ft_dtoa(nbr < 0 ? -nbr : nbr, res, params->precision ? params->precision : 6);
	if (nbr < 0)
		res--;
	ft_format_str(res, params);
}
