/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:39:12 by tkremnov          #+#    #+#             */
/*   Updated: 2024/12/17 10:49:10 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "ft_printf.h"

static int	ft_handle_specifier(va_list args, const char *specifier);
static int	ft_va_end(va_list args);

int	ft_printf(const char *specifier, ...)
{
	va_list	args;
	int		print_len;
	int		total;

	print_len = 0;
	if (specifier == NULL)
		return (-1);
	va_start(args, specifier);
	while (*specifier)
	{
		if (*specifier == '%' && *(specifier + 1) == '\0')
			return (ft_va_end(args));
		if (*specifier == '%')
			total = ft_handle_specifier(args, ++specifier);
		else
			total = ft_printf_putchar(*specifier);
		specifier++;
		if (total == -1)
			return (ft_va_end(args));
		print_len += total;
	}
	va_end(args);
	return (print_len);
}

static int	ft_handle_specifier(va_list args, const char *specifier)
{
	if (*specifier == 'c')
		return (ft_printf_putchar(va_arg(args, int)));
	else if (*specifier == 's')
		return (ft_printf_putstr(va_arg(args, char *)));
	else if (*specifier == 'p')
		return (ft_printf_putpntr((unsigned long long)va_arg(args, void *)));
	else if (*specifier == 'd' || *specifier == 'i')
		return (ft_printf_putnbr(va_arg(args, int)));
	else if (*specifier == 'u')
		return (ft_printf_putunsig(va_arg(args, unsigned int)));
	else if (*specifier == 'x')
		return (ft_printf_hexlow((unsigned long)va_arg(args, unsigned int)));
	else if (*specifier == 'X')
		return (ft_printf_hexup((unsigned long)va_arg(args, unsigned int)));
	else if (*specifier == '%')
		return (ft_printf_putchar('%'));
	else
		return (write(1, (specifier - 1), 2));
	return (0);
}

static int	ft_va_end(va_list args)
{
	va_end(args);
	return (-1);
}
