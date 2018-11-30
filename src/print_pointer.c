/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:24:52 by yochered          #+#    #+#             */
/*   Updated: 2018/11/30 11:24:53 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_putpointer(va_list ap, t_params *params)
{
	long long	addr;
	char 		*res;
	char 		*res_tmp;

	addr = va_arg(ap, long long);
	res_tmp = ft_ll_itoa_base(addr, 16);
	if (!(res = (char*)malloc(sizeof(char) * ((ft_strlen(res_tmp))) + 2)))
		return ;
	ft_strcpy(res, "0x");
	ft_strcpy(res + 2, res_tmp);
	free(res_tmp);
	res_tmp = res;
	while (*res_tmp++)
		if (*res_tmp >= 'A' && *res_tmp <= 'F')
			*res_tmp += 32;
	ft_putstr(res, params);
	free(res);
}
