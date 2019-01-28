/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:31:32 by yochered          #+#    #+#             */
/*   Updated: 2018/12/11 16:31:38 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		allowed_s(char *str)
{
	if (!(FL(*str)) && *str != '*' && *str != '.' && type_id(*str, NULL) == -1
		&& !CL(*str) && !ft_isdigit(*str) && *str != '%')
		return (0);
	return (1);
}

void	handle_flags(t_fmt *fmt)
{
	char	*flags;
	int		i;

	flags = FLAGS;
	while (FL(*(fmt->str)))
	{
		i = -1;
		while (flags[++i])
			if (flags[i] == *(fmt->str))
				fmt->flag |= ft_power(2, i);
		fmt->str++;
	}
}

void	handle_width(t_fmt *fmt, va_list ap)
{
	if (*(fmt->str) == '*')
	{
		fmt->width = va_arg(ap, int);
		fmt->flag |= width;
		fmt->str++;
	}
	else if (ft_isdigit(*(fmt->str)))
	{
		fmt->width = ft_atoi(fmt->str);
		fmt->flag |= width;
		while (ft_isdigit(*(fmt->str)))
			fmt->str++;
	}
	if (fmt->flag & width && fmt->width < 0)
	{
		fmt->flag |= minus;
		fmt->width = -fmt->width;
	}
}

void	handle_precision(t_fmt *fmt, va_list ap)
{
	if (*(fmt->str) == '.' && *(fmt->str + 1) == '*')
	{
		fmt->prec = va_arg(ap, int);
		fmt->flag |= fmt->prec >= 0 ? precision : 0;
		fmt->str += 2;
	}
	else if (*(fmt->str) == '.' && ft_isdigit(*(fmt->str + 1)))
	{
		fmt->str++;
		fmt->prec = ft_atoi(fmt->str);
		fmt->flag |= fmt->prec >= 0 ? precision : 0;
		while (ft_isdigit(*(fmt->str)))
			fmt->str++;
	}
	else if (*(fmt->str) == '.' && !ft_isdigit(*(fmt->str + 1)))
	{
		fmt->str++;
		fmt->prec = 0;
		fmt->flag |= fmt->prec >= 0 ? precision : 0;
	}
}

void	handle_length(t_fmt *fmt)
{
	if (*(fmt->str) == 'h' && *(fmt->str + 1) != 'h' && fmt->conv < h)
		fmt->conv = h;
	else if (*(fmt->str) == 'h' && *(fmt->str + 1) == 'h')
		fmt->conv = hh;
	else if (*(fmt->str) == 'l' && *(fmt->str + 1) != 'l' && fmt->conv < l)
		fmt->conv = l;
	else if (*(fmt->str) == 'l' && *(fmt->str + 1) == 'l' && fmt->conv < ll)
		fmt->conv = ll;
	else if (*(fmt->str) == 'j' && fmt->conv < j)
		fmt->conv = j;
	else if (*(fmt->str) == 'z' && fmt->conv < z)
		fmt->conv = z;
	else if (*(fmt->str) == 'L')
		fmt->conv = L;
	fmt->str += fmt->conv == hh || fmt->conv == ll ? 2 : 1;
}
