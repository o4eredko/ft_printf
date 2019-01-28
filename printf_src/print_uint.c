/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:04:14 by yochered          #+#    #+#             */
/*   Updated: 2018/11/29 10:04:16 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

uintmax_t	convert_unsigned_arg(va_list ap, t_fmt *fmt)
{
	uintmax_t nbr;

	nbr = va_arg(ap, uintmax_t);
	if (fmt->conv == hh)
		nbr = (unsigned char)nbr;
	else if (fmt->conv == h)
		nbr = (unsigned short)nbr;
	else if (fmt->conv == l)
		nbr = (unsigned long)nbr;
	else if (fmt->conv == ll)
		nbr = (unsigned long long)nbr;
	else if (fmt->conv == j)
		nbr = (uintmax_t)nbr;
	else if (fmt->conv == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

int			ft_va_putunbr(va_list ap, t_fmt *fmt)
{
	char		*str;
	uintmax_t	nbr;
	size_t		len;

	nbr = convert_unsigned_arg(ap, fmt);
	len = (size_t)count_unsigned_digits(nbr, 10);
	if (fmt->flag & precision)
		len = (int)len < fmt->prec ? fmt->prec : (int)len;
	str = ft_strnew(len);
	uint_to_str(str, nbr, 10, fmt);
	if (fmt->flag & hash)
		fmt->flag = fmt->flag & ~(1 << (5 - 1));
	if (fmt->flag & zero && fmt->flag & precision)
		fmt->flag = fmt->flag & ~(1 << (3 - 1));
	return (ft_format_str(str, fmt));
}

int			ft_va_putoctal(va_list ap, t_fmt *fmt)
{
	char		*str;
	char		*str_tmp;
	uintmax_t	nbr;
	size_t		len;

	nbr = convert_unsigned_arg(ap, fmt);
	len = (size_t)count_unsigned_digits(nbr, 8);
	if (fmt->flag & precision)
		len = (int)len < fmt->prec ? fmt->prec : (int)len;
	str = ft_strnew(len);
	str_tmp = str;
	if (!(!nbr && (fmt->flag & precision && !fmt->prec)))
		uint_to_str(str, nbr, 8, fmt);
	if (fmt->flag & hash && (nbr > 0 || fmt->flag & precision)
		&& (!(fmt->flag & precision)
	|| fmt->prec <= count_unsigned_digits(nbr, 8)))
	{
		str = ft_strnew(1);
		ft_strcp(str, "0");
		str = ft_strjoin_free(str, str_tmp);
	}
	if (fmt->flag & zero && fmt->flag & precision)
		fmt->flag = fmt->flag & ~(1 << (3 - 1));
	return (ft_format_str(str, fmt));
}

int			ft_va_puthex(va_list ap, t_fmt *fmt)
{
	char		*str;
	char		*str_tmp;
	uintmax_t	nbr;
	size_t		len;

	nbr = convert_unsigned_arg(ap, fmt);
	len = (size_t)count_unsigned_digits(nbr, 16);
	if (fmt->flag & precision)
		len = (int)len < fmt->prec ? fmt->prec : (int)len;
	str = ft_strnew(len);
	str_tmp = str;
	if (!(!nbr && (fmt->flag & precision && !fmt->prec)))
		uint_to_str(str, nbr, 16, fmt);
	if (fmt->flag & hash && nbr > 0)
	{
		str = ft_strnew(2);
		ft_strcp(str, "0x");
		str = ft_strjoin_free(str, str_tmp);
	}
	if (fmt->flag & zero && fmt->flag & precision)
		fmt->flag = fmt->flag & ~(1 << (3 - 1));
	if (fmt->type == 'X')
		ft_strtoupper(str);
	return (ft_format_str(str, fmt));
}
