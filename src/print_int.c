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

	if (params->flag == 'c')
		nbr = (char)va_arg(ap, int);
	else if (params->flag == 'h')
		nbr = (unsigned short)va_arg(ap, int);
	else if (params->flag == 'i')
		nbr = va_arg(ap, long long);
	else if (params->flag == 'l')
		nbr = va_arg(ap, long);
	else
		nbr = va_arg(ap, int);
	str = ft_ll_itoa_base(nbr, 10);
	ft_putstr(str, params);
	free(str);
}

void 	ft_va_putunbr(va_list ap, t_params *params)
{
	char				*str;
	unsigned long long	nbr;

	if (params->flag == 'c')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (params->flag == 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (params->flag == 'i')
		nbr = va_arg(ap, unsigned long long);
	else if (params->flag == 'l')
		nbr = va_arg(ap, unsigned long);
	else
		nbr = va_arg(ap, unsigned int);
	str = ft_ll_itoa_base(nbr, 10);
	ft_putstr(str, params);
	free(str);
}

void	ft_va_putoctal(va_list ap, t_params *params)
{
	unsigned long long	nbr;
	char				*res;

	if (params->flag == 'c')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (params->flag == 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (params->flag == 'i')
		nbr = va_arg(ap, unsigned long long);
	else if (params->flag == 'l')
		nbr = va_arg(ap, unsigned long);
	else
		nbr = va_arg(ap, unsigned int);
	res = ft_ll_itoa_base(nbr, 8);
	ft_putstr(res, params);
	free(res);
}

void	ft_va_puthex(va_list ap, t_params *params)
{
	unsigned long long	nbr;
	char				*res;

	if (params->flag == 'c')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (params->flag == 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (params->flag == 'i')
		nbr = va_arg(ap, unsigned long long);
	else if (params->flag == 'l')
		nbr = va_arg(ap, unsigned long);
	else
		nbr = va_arg(ap, unsigned int);
	res = ft_ll_itoa_base(nbr, 16);
	ft_putstr(res, params);
	free(res);
}

void	ft_va_l_puthex(va_list ap, t_params *params)
{
	unsigned long long	nbr;
	char				*res;
	char 			*res_tmp;

	if (params->flag == 'c')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (params->flag == 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (params->flag == 'i')
		nbr = va_arg(ap, unsigned long long);
	else if (params->flag == 'l')
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
	ft_putstr(res, params);
	free(res);
}
