/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:36:16 by tkremnov          #+#    #+#             */
/*   Updated: 2024/12/17 10:05:11 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "ft_printf.h"

int	ft_printf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_putstr(char *s)
{
	if (s == NULL)
		s = "(null)";
	return (write(1, s, ft_strlen(s)));
}

int	ft_printf_putnbr(int n)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -n;
		len++;
	}
	if (num >= 10)
		len += ft_printf_putnbr(num / 10);
	num = (num % 10) + '0';
	len += (write(1, &num, 1));
	return (len);
}

int	ft_printf_putunsig(unsigned int num)
{
	char	buffer[11];
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
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
	{
		len += write(1, &buffer[--i], 1);
	}
	return (len);
}
