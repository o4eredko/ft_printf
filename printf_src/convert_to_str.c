/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:05:07 by yochered          #+#    #+#             */
/*   Updated: 2018/11/29 10:05:08 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			count_unsigned_digits(uintmax_t value, int base)
{
	int digits;

	digits = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		digits++;
		value /= base;
	}
	return (digits);
}

int			count_signed_digits(intmax_t value, int base)
{
	int digits;

	digits = 0;
	if (value <= 0)
		digits++;
	while (value)
	{
		digits++;
		value /= base;
	}
	return (digits);
}

void		uint_to_str(char *res, uintmax_t nbr, int base, t_fmt *fmt)
{
	char	*base_digits;
	int		i;

	base_digits = "0123456789abcdef";
	i = 0;
	if (nbr == 0 && !(fmt->flag & precision))
		res[i++] = '0';
	while (nbr)
	{
		res[i++] = base_digits[nbr % base];
		nbr /= base;
	}
	while (i < fmt->prec && fmt->flag & precision)
		res[i++] = '0';
	ft_strrev(res, i);
}

void		int_to_str(char *res, intmax_t nbr, int base, t_fmt *fmt)
{
	char		*base_digits;
	int			i;
	intmax_t	nbr_tmp;

	nbr_tmp = nbr;
	base_digits = "0123456789abcdef";
	i = 0;
	if (nbr == 0 && fmt && !(fmt->flag & precision))
		res[i++] = '0';
	while (nbr)
	{
		res[i++] = base_digits[(nbr < 0 ? -(nbr % base) : nbr % base)];
		nbr /= base;
	}
	while (fmt && i < fmt->prec && fmt->flag & precision)
		res[i++] = '0';
	if (nbr_tmp < 0)
		res[i++] = '-';
	ft_strrev(res, i);
}

void	print_buf(t_fmt *fmt, char *src, int size)
{
	while (size--)
	{
		if (fmt->buf_i == BUFF - 1)
		{
			write(1, fmt->buf, BUFF);
			fmt->buf_i = 0;
		}
		fmt->buf[fmt->buf_i++] = *src++;
	}
}
