/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:03:45 by yochered          #+#    #+#             */
/*   Updated: 2018/11/25 18:03:46 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long ft_power(int nb, int power)
{
	long long res;

	res = 1;
	if (power <= 0)
		return (1);
	while (power--)
		res *= nb;
	return (res);
}

void		ft_va_putfloat(va_list ap, t_params *params)
{
	long double	nbr;
	char 		*res;
	char 		*res_tmp;

	if (params->flag == 'L')
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	res = ft_strnew((unsigned int)(count_digits(((int)nbr), 10) + 1 + params->precision));
	res_tmp = ft_itoa_base((int)nbr, 10);
	ft_strcpy(res, res_tmp);
	free(res_tmp);
	res_tmp = res;
	res += ft_strlen(res);
	nbr = (nbr - (int)nbr) * (nbr < 0 ? -1 : 1);
	*res++ = '.';
	nbr *= ft_power(10, params->precision);
	ft_strcpy(res, ft_itoa_base((int)(nbr + 0.5), 10));
	ft_putstr(res_tmp, params);
	free(res_tmp);
}

//void		ft_put_s_notation(double nb, t_params *params)
//{
//	int		exp;
//	int 	len;
//	char	*res;
//	char	*res_tmp;
//
//	exp = 1;
//	len = 6 + 6;//+presicion
//	res = ft_strnew((unsigned int)len);
//	while ((int)nb / ft_power(10, exp) < 0 || (int)nb / ft_power(10, exp) > 9)
//		exp++;
//	res_tmp = ft_itoa_base(exp, 10);
//	ft_strcpy(&res[len - 4], exp >= 0 ? "e+" : "e-");
//	if (exp > 10)
//		res[len - 2] = '0';
//	ft_strcpy(&res[exp < 10 && exp > -10 ? len - 1 : len - 2], res_tmp);
//	len -= 6 + ft_strlen(res_tmp);
//	free(res_tmp);
//	res_tmp = res;
//	*res++ = (int)nb + '0';
//	*res++ = '.';
//	while (len--)
//	{
//		nb *= 10;
//		*res++ = ((int)nb) ? nb + '0' : '0';
//		nb -= (int)nb;
//	}
//	ft_putstr(res_tmp, params);
//	free(res_tmp);
//}
