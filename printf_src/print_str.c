/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:08:38 by yochered          #+#    #+#             */
/*   Updated: 2018/11/29 10:08:39 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	skip_flag_symbols(t_fmt *fmt, char **s)
{
	int len;

	len = 0;
	if ((fmt->flag & hash && (fmt->type == 'o'))
		|| **s == '+' || **s == '-' || **s == ' ')
		len = 1;
	if (*(*s + 1) == 'x' || *(*s + 1) == 'X' || *(*s + 1) == 'b')
		len = 2;
	print_buf(fmt, *s, (unsigned int)len);
	fmt->width -= len;
	*s += len;
}

int		ft_format_str(char *s, t_fmt *fmt)
{
	int		len;
	char	*str_tmp;

	len = (int)ft_strlen(s);
	len = fmt->flag & width && fmt->width > len ? fmt->width : len;
	str_tmp = s;
	if (fmt->flag & width && !(fmt->flag & minus)
		&& !(fmt->flag & zero))
		print_padding(fmt, fmt->width - (int)ft_strlen(s), ' ');
	if (fmt->flag & width && !(fmt->flag & minus) && fmt->flag & zero)
	{
		if (fmt->flag & hash || *s == '+' || *s == '-' || *s == ' '
		|| fmt->type == 'p')
			skip_flag_symbols(fmt, &s);
		print_padding(fmt, fmt->width - (int)ft_strlen(s), '0');
	}
	print_buf(fmt, s, (int)ft_strlen(s));
	if (fmt->flag & width && fmt->flag & minus)
		print_padding(fmt, fmt->width - (int)ft_strlen(s), ' ');
	free(str_tmp);
	return (len);
}

int		ft_va_putchar(va_list ap, t_fmt *fmt)
{
	int		len;
	char	c;

	c = (char)va_arg(ap, int);
	len = 1;
	if (fmt->flag & width)
		len = fmt->width > len ? fmt->width : len;
	if (fmt->flag & width && !(fmt->flag & minus))
		print_padding(fmt, fmt->width - 1, (fmt->flag & zero) ? '0' : ' ');
	print_buf(fmt, &c, 1);
	if (fmt->flag & width && fmt->flag & minus)
		print_padding(fmt, fmt->width - 1, ' ');
	return (len);
}

int		ft_va_putstr(va_list ap, t_fmt *fmt)
{
	char	*s;
	char	*res;

	s = va_arg(ap, char*);
	if (!s)
		s = "(null)";
	res = ft_strdup(s);
	if (fmt->flag & precision && fmt->prec < (int)ft_strlen(s))
	{
		s = ft_strsub(res, 0, (size_t)fmt->prec);
		free(res);
		res = s;
	}
	if (fmt->flag & hash)
		fmt->flag = fmt->flag & ~(1 << (5 - 1));
	return (ft_format_str(res, fmt));
}

int		print_percent(char c, t_fmt *fmt)
{
	int len;

	len = c ? 1 : 0;
	if (fmt->flag & width)
		len = fmt->width > len ? fmt->width : len;
	if (fmt->flag & width && !(fmt->flag & minus))
		print_padding(fmt, fmt->width - 1, fmt->flag & zero ? '0' : ' ');
	if (c)
		print_buf(fmt, &c, 1);
	if (fmt->flag & width && fmt->flag & minus)
		print_padding(fmt, fmt->width - 1, ' ');
	return (len);
}
