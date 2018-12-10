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

double		ft_pow(double nbr, int pow)
{
	double res;

	res = 1;
	while (pow)
	{
		res = pow < 0 ? res / nbr : res * nbr;
		pow += pow < 0 ? 1 : -1;
	}
	return (res);
}

int			ft_int_to_str(intmax_t nbr, char *res, int precision)
{
	int i;

	i = 0;
	while (nbr)
	{
		res[i++] = (char)((nbr < 0 ? -(nbr % 10) : nbr % 10) + '0');
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
	int			k;

	i = ft_int_to_str((intmax_t)nbr, res, 1);
	nbr -= (intmax_t)nbr;
	k = -1;
	nbr += 0.5 / ft_pow(10, precision);
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
	char		*res;

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
			*res++ = (char)(params->flag & space && !(params->flag & plus) ? ' ' : '+');
	}
	ft_dtoa(ABS(nbr), res, params->flag & precision
		? params->precision : 6);
	if (nbr < 0 || params->flag & plus || params->flag & space)
		res--;
	return (ft_format_str(res, params));
}

void	ft_dtosn(long double nbr, char *res, int precision)
{
	int exp;
	int i;

	i = 0;
	exp = 0;
	while (nbr / ft_pow(10, exp) >= 10 || nbr / ft_pow(10, exp) < 1)
		exp += nbr < 1 ? -1 : 1;
	nbr /= ft_pow(10, exp);
	res[i++] = (char)((intmax_t)(nbr) + '0');
	nbr -= (intmax_t)nbr;
	nbr += 0.5 / ft_pow(10, precision);
	if (precision)
	{
		res[i++] = '.';
		while (precision--)
		{
			nbr *= 10;
			res[i++] = (char)((int)nbr + 48);
			nbr -= (int)nbr;
		}
	}
	ft_strcpy(&res[i], exp < 0 ? "e-" : "e+");
	i += 2;
	ft_int_to_str(ABS(exp), &res[i], 2);
}

int 	ft_va_putsnotation(va_list ap, t_params *params)
{
	char		*res;
	long double	nbr;

	if (params->e_convert == L)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	res = ft_strnew(6 + params->flag & precision ? (size_t)params->precision : 6);
	if (nbr < 0 || params->flag & plus || params->flag & space)
	{
		if (nbr < 0)
			*res++ = '-';
		else
			*res++ = (char)(params->flag & space && !(params->flag & plus) ? ' ' : '+');
	}
	ft_dtosn(ABS(nbr), res, params->flag & precision ? params->precision : 6);
	if (nbr < 0 || params->flag & plus || params->flag & space)
		res--;
	return (ft_format_str(res, params));
}
