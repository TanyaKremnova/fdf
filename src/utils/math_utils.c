/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:54:57 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:45:17 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	hex_to_int(const char *hex)
{
	int	result;
	int	value;

	result = 0;
	if (!hex || !*hex)
		return (-1);
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		hex += 2;
	while (*hex)
	{
		if (ft_isdigit(*hex))
			value = *hex - '0';
		else if (*hex >= 'A' && *hex <= 'F')
			value = *hex - 'A' + 10;
		else if (*hex >= 'a' && *hex <= 'f')
			value = *hex - 'a' + 10;
		else
			return (-1);
		result = (result * 16) + value;
		hex++;
	}
	return (result);
}
