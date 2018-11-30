/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:14:45 by yochered          #+#    #+#             */
/*   Updated: 2018/11/29 10:14:46 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (string[len] != '\0')
		len++;
	return (len);
}

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	res = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	if (!res)
		return (NULL);
	while (i < size)
		res[i++] = '\0';
	res[i] = '\0';
	return (res);
}

char	*ft_strcpy(char *dst, const char *src)
{
	char *dst_tmp;

	dst_tmp = dst;
	while (*src)
		*dst_tmp++ = *src++;
	return (dst);
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int			ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (9223372036854775807 - res < *str - 48)
			return (sign == -1 ? 0 : -1);
		res = res * 10 + (*str - 48);
		str++;
	}
	return ((int)res * sign);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
