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

#include "ft_printf.h"

int 		count_unsigned_digits(uintmax_t value, int base)
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

int 		count_signed_digits(intmax_t value, int base)
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

void 		uint_to_str(char *res, uintmax_t nbr, int base, t_params *params)
{
	char 	*base_digits;
	int		i;

	base_digits = "0123456789abcdef";
	i = 0;
	if (nbr == 0 && !(params->flag & precision))
		res[i++] = '0';
	while (nbr)
	{
		res[i++] = base_digits[nbr % base];
		nbr /= base;
	}
	while (i < params->precision && params->flag & precision)
		res[i++] = '0';
	ft_strrev(res, i);
}

void 		int_to_str(char *res, intmax_t nbr, int base, t_params *params)
{
	char 		*base_digits;
	int			i;
	intmax_t	nbr_tmp;

	nbr_tmp = nbr;
	base_digits = "0123456789abcdef";
	i = 0;
	if (nbr == 0 && !(params->flag & precision))
		res[i++] = '0';
	while (nbr)
	{
		res[i++] = base_digits[(nbr < 0 ? -(nbr % base) : nbr % base)];
		nbr /= base;
	}
	while (i < params->precision && params->flag & precision)
		res[i++] = '0';
	if (nbr_tmp < 0)
		res[i++] = '-';
	ft_strrev(res, i);
}

int 		count_u_digits(unsigned int value, int base)
{
	int digits;

	digits = 0;
	if (value == 0)
		digits++;
	while (value != 0)
	{
		digits++;
		value /= base;
	}
	return (digits);
}

char		*ft_itoa_base(intmax_t value, int base)
{
	char	*res;
	char	*base_digits;
	int		digits;

	base_digits = "0123456789ABCDEF";
	digits = count_signed_digits(value, base);
	if (!(res = (char *)malloc((digits + 1) * sizeof(char))))
		return (NULL);
	if (value < 0 && base == 10)
		res[0] = '-';
	if (value == 0)
		res[0] = '0';
	res[digits] = '\0';
	while (value && digits-- > 0)
	{
		res[digits] = value < 0 ? base_digits[-(value % base)] :
					  base_digits[(value % base)];
		value /= base;
	}
	return (res);
}

char		*ft_uitoa_base(unsigned int value, int base)
{
	char	*res;
	char	*base_digits;
	int		digits;

	base_digits = "0123456789ABCDEF";
	digits = count_unsigned_digits(value, base);
	if (!(res = (char *)malloc((digits + 1) * sizeof(char))))
		return (NULL);
	if (value == 0)
		res[0] = '0';
	res[digits] = '\0';
	while (value && digits-- > 0)
	{
		res[digits] = base_digits[(value % base)];
		value /= base;
	}
	return (res);
}
