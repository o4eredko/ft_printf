#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int 	ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
