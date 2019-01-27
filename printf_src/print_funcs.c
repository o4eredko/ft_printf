/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:56:28 by yochered          #+#    #+#             */
/*   Updated: 2018/12/10 11:56:29 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	print_padding(int size, char c)
{
	while (size-- > 0)
		ft_putchar(c);
}

int		print_percent(char c, t_fmt *fmt)
{
	int len;

	len = c ? 1 : 0;
	if (fmt->flag & width)
		len = fmt->width > len ? fmt->width : len;
	if (fmt->flag & width && !(fmt->flag & minus))
		print_padding(fmt->width - 1, fmt->flag & zero ? '0' : ' ');
	if (c)
		ft_putchar(c);
	if (fmt->flag & width && fmt->flag & minus)
		print_padding(fmt->width - 1, ' ');
	return (len);
}
