#include "ft_printf.h"

int	ft_va_putbinary(va_list ap, t_params *params)
{
	uintmax_t	nbr;
	int 		len;
	char		*res;
	char 		*res_tmp;

	nbr = convert_unsigned_arg(ap, params);
	len = (size_t)count_unsigned_digits(nbr, 2);
	if (params->flag & precision)
		len = (int)len < params->precision ? params->precision : len;
	res = ft_strnew((size_t)len);
	if (!(!nbr && (params->flag & precision && !params->precision)))
		uint_to_str(res, nbr, 2, params);
	res_tmp = res;
	if (params->flag & hash && nbr > 0)
	{
		res = ft_strnew(2);
		ft_strcpy(res, "0b");
		res = ft_strjoin(res, res_tmp);
	}
	if (params->flag & zero && params->flag & precision)
		params->flag = params->flag & ~(1 << (3 - 1));
	return (ft_format_str(res, params));
}
