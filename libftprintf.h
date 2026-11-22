#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int	ft_printf_helper(char c, va_list args);
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int nb);
unsigned int ft_putunnbr(unsigned int nb);
int	ft_puthex(unsigned long n, char *base);
int	*ft_putptr(unsigned long ptr);

#endif
