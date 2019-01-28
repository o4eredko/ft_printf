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

#include <ft_printf.h>

void		get_limit(char *res, long double nbr, t_fmt *fmt)
{
	if (nbr != nbr)
		ft_strcp(res, "nan");
	else if (nbr == 1.0 / 0.0)
		ft_strcp(res, "inf");
	else if (nbr == -1.0 / 0.0)
		ft_strcp(res, "inf");
	*(res + 3) = '\0';
	if (fmt->type == 'F')
		ft_strtoupper(res);
	if (fmt->flag & zero)
		fmt->flag = fmt->flag & ~(1 << (3 - 1));
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

	nbr += 0.5 / ft_pow(10, precision);
	i = ft_int_to_str((intmax_t)nbr, res, 1);
	nbr -= (intmax_t)nbr;
	k = -1;
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

char		*putfloat(long double nbr, t_fmt *fmt)
{
	char	*res;

	res = ft_strnew(((size_t)count_signed_digits((intmax_t)nbr, 10)
		+ 1 + (fmt->flag & precision ? fmt->prec : 6)));
	if ((nbr < 0 || (!nbr && 1.0 / nbr == 1.0 / -0.0) || fmt->flag & plus
		|| fmt->flag & space) && nbr == nbr)
	{
		if (nbr < 0 || (!nbr && 1.0 / nbr == 1.0 / -0.0))
			*res++ = '-';
		else
			*res++ = (char)(fmt->flag & space
				&& !(fmt->flag & plus) ? ' ' : '+');
	}
	if (nbr != nbr || nbr == 1.0 / 0.0 || nbr == -1.0 / 0.0)
		get_limit(res, nbr, fmt);
	else
		ft_dtoa(ABS(nbr), res, fmt->flag & precision
			? fmt->prec : 6);
	if (fmt->flag & precision && !fmt->prec && fmt->flag & hash)
		*(res + ft_strlen(res)) = '.';
	if ((nbr < 0 || (!nbr && 1.0 / nbr == 1.0 / -0.0) || fmt->flag & plus
		|| fmt->flag & space) && nbr == nbr)
		res--;
	return (res);
}

int			ft_va_putfloat(va_list ap, t_fmt *fmt)
{
	long double	nbr;
	char		*res;

	if (fmt->conv == L)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	res = putfloat(nbr, fmt);
	return (ft_format_str(res, fmt));
}
