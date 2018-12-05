/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:50:43 by yochered          #+#    #+#             */
/*   Updated: 2018/11/30 10:50:44 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_function_arr(int (*f[10])(va_list, t_params*))
{
	f[0] = ft_va_putchar;
	f[1] = ft_va_putstr;
	f[2] = ft_va_putnbr;
	f[3] = ft_va_putunbr;
	f[4] = ft_va_putoctal;
	f[5] = ft_va_puthex;
	f[6] = ft_va_l_puthex;
	f[7] = ft_va_putpointer;
	f[8] = ft_va_putfloat;
}

int		type_id(char c)
{
	int res;

	res = -1;
	if (c == 'c')
		res = 0;
	if (c == 's')
		res = 1;
	if (c == 'd' || c == 'i')
		res = 2;
	if (c == 'u')
		res = 3;
	if (c == 'o')
		res = 4;
	if (c == 'x')
		res = 5;
	if (c == 'X')
		res = 6;
	if (c == 'p')
		res = 7;
	if (c == 'f')
		res = 8;
	return (res);
}
