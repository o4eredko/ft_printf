/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:19:04 by yochered          #+#    #+#             */
/*   Updated: 2018/12/04 16:19:05 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

intmax_t	convert_signed_arg(va_list ap, t_fmt *fmt)
{
	intmax_t nbr;

	nbr = va_arg(ap, intmax_t);
	if (fmt->conv == hh)
		nbr = (char)nbr;
	else if (fmt->conv == h)
		nbr = (short)nbr;
	else if (fmt->conv == l)
		nbr = (long)nbr;
	else if (fmt->conv == ll)
		nbr = (long long)nbr;
	else if (fmt->conv == j)
		nbr = (intmax_t)nbr;
	else if (fmt->conv == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

int			ft_va_putnbr(va_list ap, t_fmt *fmt)
{
	char		*str;
	char		*str_tmp;
	intmax_t	nbr;
	size_t		len;

	nbr = convert_signed_arg(ap, fmt);
	len = (size_t)count_signed_digits(nbr, 10);
	if (fmt->flag & precision)
		len = len < (size_t)fmt->prec ? (size_t)fmt->prec : len;
	if (((fmt->flag & plus || fmt->flag & space) && nbr >= 0) || nbr < 0)
		str = ft_strnew(len + 1);
	else
		str = ft_strnew(len);
	str_tmp = str;
	if (fmt->flag & space && !(fmt->flag & plus) && nbr >= 0)
		*str_tmp++ = ' ';
	if (fmt->flag & plus && nbr >= 0)
		*str_tmp++ = '+';
	if (!(!nbr && (fmt->flag & precision && !fmt->prec)))
		int_to_str(str_tmp, nbr, 10, fmt);
	if (fmt->flag & hash)
		fmt->flag = fmt->flag & ~(1 << (5 - 1));
	if (fmt->flag & zero && fmt->flag & precision)
		fmt->flag = fmt->flag & ~(1 << (3 - 1));
	return (ft_format_str(str, fmt));
}

int	ft_va_putpointer(va_list ap, t_fmt *fmt)
{
	uintmax_t	addr;
	char		*res;
	size_t		len;
	char		*res_tmp;

	addr = va_arg(ap, uintmax_t);
	len = (size_t)count_unsigned_digits(addr, 16);
	len = (size_t)(fmt->flag & precision && fmt->prec > (int)len ?
				   fmt->prec : (int)len);
	res_tmp = ft_strnew(len);
	uint_to_str(res_tmp, addr, 16, fmt);
	if (!addr && fmt->flag & precision && !fmt->prec)
		ft_strclr(res_tmp);
	res = ft_strnew(sizeof(char) * (len + 2));
	ft_strcp(res, "0x");
	ft_strcp(res + 2, res_tmp);
	free(res_tmp);
	ft_strtolower(res);
	return (ft_format_str(res, fmt));
}
