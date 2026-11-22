/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydames <ydames@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 05:56:08 by ydames            #+#    #+#             */
/*   Updated: 2026/11/22 07:04:26 by ydames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// * Supported specifiers:
// * - %c : character
// * - %s : string
// * - %d : signed integer
// * - %i : signed integer
// * - %u : unsigned integer
// * - %x : hexadecimal (lowercase)
// * - %X : hexadecimal (uppercase)
// * - %p : pointer address
// * - %% : percent sign

int	ft_printf_helper(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunnbr(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == 'P')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF"));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr(int nb)
{
	long	nbr;
	int		count;

	nbr = nb;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	else if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

unsigned int	ft_putunnbr(unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, base);
	count += ft_putchar((base[n % 16]));
	return (count);
}

int	*ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		return (ft_putstr("(nil)"));
	}
	count += ft_putstr("0x");
	count += ft_puthex(ptr, "0123456789abcdef");
	return (count);
}
