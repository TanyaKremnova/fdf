/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:38:50 by tkremnov          #+#    #+#             */
/*   Updated: 2024/12/17 10:05:15 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "ft_printf.h"

int	ft_printf_putpntr(unsigned long long num)
{
	char	*hex_digits;
	char	buffer[16];
	int		i;
	int		len;

	hex_digits = "0123456789abcdef";
	i = 0;
	len = 0;
	if (num == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	while (num > 0)
	{
		buffer[i++] = hex_digits[num % 16];
		num /= 16;
	}
	while (i > 0)
		len += write(1, &buffer[--i], 1);
	return (len);
}

int	ft_printf_puthex(unsigned long num, char *hex_digits)
{
	char	buffer[16];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (num == 0)
	{
		return (write(1, "0", 1));
	}
	while (num > 0)
	{
		buffer[i++] = hex_digits[num % 16];
		num /= 16;
	}
	while (i > 0)
	{
		len += write(1, &buffer[--i], 1);
	}
	return (len);
}

int	ft_printf_hexlow(unsigned long num)
{
	return (ft_printf_puthex(num, "0123456789abcdef"));
}

int	ft_printf_hexup(unsigned long num)
{
	return (ft_printf_puthex(num, "0123456789ABCDEF"));
}
