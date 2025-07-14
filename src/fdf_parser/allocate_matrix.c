/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:44:37 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:48 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_dot	**allocate_matrix(int height)
{
	t_dot	**matrix;

	matrix = malloc(sizeof(t_dot *) * height);
	if (!matrix)
		return (NULL);
	return (matrix);
}
