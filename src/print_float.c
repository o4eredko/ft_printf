/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:25:19 by yochered          #+#    #+#             */
/*   Updated: 2018/12/04 18:25:20 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_round(char *str, int i)
{
	int flag;

	flag = 0;
	if (str[i] >= '5' && str[i - 1] != '.')
	{
		str[i]++;
		flag = 1;
		str[i] = str[i] == ':' ? '0' : str[i];
	}
	while (i && str[i - 1] != '.' && str[i - 2] != '.')
	{
		if (str[i] >= '5' || flag)
		{
			str[i - 1]++;
			flag = 1;
		}
		else
			flag = 0;
		str[i] = str[i] == ':' ? '0' : str[i];
		i--;
	}
}

int		ft_int_to_str(intmax_t nbr, char *res, int precision)
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
	intmax_t 	i_part;
	long double	f_part;
	int			i;

	i_part = (intmax_t)nbr;
	f_part = nbr - (long double)i_part;
	i = ft_int_to_str(i_part, res, 1);
	if (precision)
	{
		res[i] = '.';
		while (precision--)
		{
			f_part *= 10;
			res[++i] = (int)f_part + 48;
			f_part -= (intmax_t)f_part;
//			if (!precision)
//				res[++i] = (int)(f_part * 10) % 10 + 48;
		}
//		ft_round(res, i);
//		res[i] = '\0';
	}
}

int			ft_va_putfloat(va_list ap, t_params *params)
{
	long double	nbr;
	char 		*res;

	if (params->e_convert == L)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	res = ft_strnew(((size_t)count_signed_digits((intmax_t)nbr, 10)
			+ 1 + (params->flag & precision ? params->precision : 6)));
	if (nbr < 0)
		*res++ = '-';
	ft_dtoa(nbr < 0 ? -nbr : nbr, res, params->flag & precision ? params->precision : 6);
	if (nbr < 0)
		res--;
	return (ft_format_str(res, params));
}