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
	int			i;
	int 		k;

	k = -1;
	i = ft_int_to_str((intmax_t)nbr, res, 1);
	nbr -= (intmax_t)nbr;
	k = -1;
	nbr += 0.5 / ft_power(10, precision);
	if (precision)
	{
		res[i++] = '.';
		while (++k < precision)
		{
			nbr *= 10;
			res[i++] = (char)((int)nbr + 48);
			nbr -= (int)nbr;
		}
	}
	res[i] = '\0';
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
	if (nbr < 0 || params->flag & plus || params->flag & space)
	{
		if (nbr < 0)
			*res++ = '-';
		else
			*res++ = params->flag & space && !(params->flag & plus) ? ' ' : '+';
	}
	ft_dtoa(nbr < 0 ? -nbr : nbr, res, params->flag & precision ? params->precision : 6);
	if (nbr < 0 || params->flag & plus || params->flag & space)
		res--;
	return (ft_format_str(res, params));
}