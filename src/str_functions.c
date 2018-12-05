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

intmax_t ft_power(intmax_t nb, int power)
{
	intmax_t	res;

	res = 1;
	if (power <= 0)
		return (1);
	while (power--)
		res *= nb;
	return (res);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh_str;
	char	*str;
	size_t	i;

	i = 0;
	fresh_str = (char *)malloc((len + 1) * sizeof(char));
	if (!fresh_str || !s)
		return (NULL);
	str = (char *)s;
	while (str[start] != '\0' && i < len)
		fresh_str[i++] = str[start++];
	fresh_str[i] = '\0';
	return (fresh_str);
}

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (string[len] != '\0')
		len++;
	return (len);
}

void		str_toupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	if ((char)c == '\0')
		return (str + ft_strlen(str));
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}

void		ft_strrev(char *str, int len)
{
	char	c;
	int 	i;

	i = -1;
	while (++i < --len)
	{
		c = str[i];
		str[i] = str[len];
		str[len] = c;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	if (len)
	{
		while (len--)
			*ptr++ = (unsigned char)c;
	}
	return (b);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_tmp;
	char	*res_tmp;
	char 	*res;

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

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	while (*s)
		*s++ = '\0';
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

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2 || !n)
		return (1);
	while (n > 0)
	{
		if (!s1[i] && !s2[i])
			return (1);
		if (s1[i] != s2[i])
			return (0);
		n--;
		i++;
	}
	return (1);
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
