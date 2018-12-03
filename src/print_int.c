/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:04:14 by yochered          #+#    #+#             */
/*   Updated: 2018/11/29 10:04:16 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_va_putnbr(va_list ap, t_params *params)
{
	char		*str;
	long long	nbr;

	if (find_flag(params->flag, 'c'))
		nbr = (char)va_arg(ap, int);
	else if (find_flag(params->flag, 'h'))
		nbr = (short)va_arg(ap, int);
	else if (find_flag(params->flag, 'i'))
		nbr = va_arg(ap, long long);
	else if (find_flag(params->flag, 'l'))
		nbr = va_arg(ap, long);
	else
		nbr = va_arg(ap, int);
	str = ft_ll_itoa_base(nbr, 10);
	ft_format_str(str, params);
}

void 	ft_va_putunbr(va_list ap, t_params *params)
{
	char				*str;
	unsigned long long	nbr;

	if (find_flag(params->flag, 'c'))
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (find_flag(params->flag, 'h'))
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (find_flag(params->flag, 'i'))
		nbr = va_arg(ap, unsigned long long);
	else if (find_flag(params->flag, 'l') || find_flag(params->flag, 'z'))
		nbr = va_arg(ap, unsigned long);
	else
		nbr = va_arg(ap, unsigned int);
	str = ft_ll_itoa_base(nbr, 10);
	ft_format_str(str, params);
}

void	ft_va_putoctal(va_list ap, t_params *params)
{
	unsigned long long	nbr;
	char				*res;

	if (find_flag(params->flag, 'c'))
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (find_flag(params->flag, 'h'))
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (find_flag(params->flag, 'i'))
		nbr = va_arg(ap, unsigned long long);
	else if (find_flag(params->flag, 'l') || find_flag(params->flag, 'z'))
		nbr = va_arg(ap, unsigned long);
	else
		nbr = va_arg(ap, unsigned int);
	res = ft_ll_itoa_base(nbr, 8);
	ft_format_str(res, params);
}

void	ft_va_puthex(va_list ap, t_params *params)
{
	unsigned long long	nbr;
	char				*res;

	if (find_flag(params->flag, 'c'))
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (find_flag(params->flag, 'h'))
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (find_flag(params->flag, 'i'))
		nbr = va_arg(ap, unsigned long long);
	else if (find_flag(params->flag, 'l') || find_flag(params->flag, 'z'))
		nbr = va_arg(ap, unsigned long);
	else
		nbr = va_arg(ap, unsigned int);
	res = ft_ll_itoa_base(nbr, 16);
	ft_format_str(res, params);
}

void	ft_va_l_puthex(va_list ap, t_params *params)
{
	unsigned long long	nbr;
	char				*res;
	char 			*res_tmp;

	if (find_flag(params->flag, 'c'))
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (find_flag(params->flag, 'h'))
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (find_flag(params->flag, 'i'))
		nbr = va_arg(ap, unsigned long long);
	else if (find_flag(params->flag, 'l') || find_flag(params->flag, 'z'))
		nbr = va_arg(ap, unsigned long);
	else
		nbr = va_arg(ap, unsigned int);
	res = ft_ll_itoa_base(nbr, 16);
	res_tmp = res;
	while (*res_tmp)
	{
		if (*res_tmp >= 'A' && *res_tmp <= 'Z')
			*res_tmp += 32;
		res_tmp++;
	}
	ft_format_str(res, params);
}
