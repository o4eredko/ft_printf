/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:36:21 by yochered          #+#    #+#             */
/*   Updated: 2018/12/11 16:36:22 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*ft_strjoin_free(char *s1, char *s2)
{
	char	*str_tmp;
	char	*res_tmp;
	char	*res;

	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	str_tmp = s1;
	res_tmp = res;
	while (*s1)
		*res++ = *s1++;
	if (str_tmp)
		free(str_tmp);
	str_tmp = s2;
	while (*s2)
		*res++ = *s2++;
	if (str_tmp)
		free(str_tmp);
	*res = '\0';
	return (res_tmp);
}

intmax_t	ft_power(intmax_t nb, int power)
{
	intmax_t	res;

	res = 1;
	if (power <= 0)
		return (1);
	while (power--)
		res *= nb;
	return (res);
}

char		*ft_strcp(char *dst, const char *src)
{
	char *dst_tmp;

	dst_tmp = dst;
	while (*src)
		*dst_tmp++ = *src++;
	return (dst);
}

void		print_padding(t_fmt *fmt, int size, char c)
{
	while (size-- > 0)
		print_buf(fmt, &c, 1);
}
