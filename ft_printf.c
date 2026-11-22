/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydames <ydames@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 05:48:58 by ydames            #+#    #+#             */
/*   Updated: 2026/11/22 06:34:59 by ydames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	list;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_printf_helper(str[i], list);
		}
		else
			count += ft_putstr(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}
