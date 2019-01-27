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

#include <ft_printf.h>

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
	ft_strtoupper(res);
	return (ft_format_str(res, fmt));
}
