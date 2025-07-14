/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:39:37 by tkremnov          #+#    #+#             */
/*   Updated: 2024/12/17 10:06:10 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printf_putchar(char c);
int	ft_printf_putstr(char *s);
int	ft_printf_putpntr(unsigned long long num);
int	ft_printf_putnbr(int n);
int	ft_printf_putunsig(unsigned int num);
int	ft_printf_putpntr(unsigned long long num);
int	ft_printf_puthex(unsigned long num, char *hex_digits);
int	ft_printf_hexlow(unsigned long num);
int	ft_printf_hexup(unsigned long num);

#endif
