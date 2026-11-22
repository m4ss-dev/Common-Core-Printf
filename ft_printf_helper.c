/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydames <ydames@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 05:56:08 by ydames            #+#    #+#             */
/*   Updated: 2026/11/22 08:28:31 by ydames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
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

int	ft_putptr(unsigned long ptr)
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
