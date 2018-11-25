#include "ft_printf.h"

int 	conversion_list(char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i' ||
	c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f'
	|| c == 'F' || c == 'e' || c == 'E' || c == 'p' || c == 'n');
}

void	handle_conversion(const char *format, va_list ap)
{

}

void	handle_expression(const char *format, va_list ap)
{
	while (**format)
	{
		if (flag_list(*format))
			handle_flags(*format);
		if (ft_isalnum(*format))
			handle_width(**format);
		/*Accuracy Handle*/
		if (conversions_list(*format))
			handle_conversion(format, ap);
		(*format)++;
	}
}

int ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			handle_expression(format, ap);
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
}