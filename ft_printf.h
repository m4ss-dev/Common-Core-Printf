/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydames <ydames@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 07:36:28 by ydames            #+#    #+#             */
/*   Updated: 2026/11/22 08:19:44 by ydames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf_helper(char c, va_list args);
int				ft_printf_helper2(char c, va_list args);
int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnbr(int nb);
unsigned int	ft_putunnbr(unsigned int nb);
int				ft_puthex(unsigned long n, char *base);
int				ft_putptr(unsigned long ptr);

#endif
