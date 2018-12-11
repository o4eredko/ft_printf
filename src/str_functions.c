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

#include <ft_printf.h>

void	str_toupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

void	ft_strrev(char *str, int len)
{
	char	c;
	int		i;

	i = -1;
	while (++i < --len)
	{
		c = str[i];
		str[i] = str[len];
		str[len] = c;
	}
}

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	while (*s)
		*s++ = '\0';
}

char	*ft_strcpy(char *dst, const char *src)
{
	char *dst_tmp;

	dst_tmp = dst;
	while (*src)
		*dst_tmp++ = *src++;
	return (dst);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
