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

void	fill_function_arr(int (*f[12])(va_list, t_params*))
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
	f[9] = ft_va_putbinary;
	f[10] = ft_va_putnonprint;
	f[11] = ft_va_puttime;
}

int		type_id(char c)
{
	char	*str;
	int 	i;

	i = 0;
	str = "csduoxXpfbrk";
	while (str[i])
	{
		if (c == str[i] || (c == 'i' && str[i] == 'd'))
			break ;
		i++;
	}
	return (i);
}
