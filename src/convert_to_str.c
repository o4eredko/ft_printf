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

int 		count_digits(int value, int base)
{
	int digits;

	digits = 0;
	if (value < 0 && base == 10)
		digits++;
	if (value == 0)
		digits++;
	while (value != 0)
	{
		digits++;
		value /= base;
	}
	return (digits);
}

int 		count_ll_digits(long long value, int base)
{
	int digits;

	digits = 0;
	if (value < 0 && base == 10)
		digits++;
	if (value == 0)
		digits++;
	while (value != 0)
	{
		digits++;
		value /= base;
	}
	return (digits);
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

char		*ft_itoa_base(int value, int base)
{
	char	*res;
	char	*base_digits;
	int		digits;

	if (!(base_digits = (char *)malloc(16 * sizeof(char))))
		return (NULL);
	base_digits = "0123456789ABCDEF";
	digits = count_digits(value, base);
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

	if (!(base_digits = (char *)malloc(16 * sizeof(char))))
		return (NULL);
	base_digits = "0123456789ABCDEF";
	digits = count_u_digits(value, base);
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

char		*ft_ll_itoa_base(long long value, int base)
{
	char	*res;
	char	*base_digits;
	int		digits;

	if (!(base_digits = (char *)malloc(16 * sizeof(char))))
		return (NULL);
	base_digits = "0123456789ABCDEF";
	digits = count_ll_digits(value, base);
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
