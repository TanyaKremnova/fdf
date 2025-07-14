/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:16:54 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:45:03 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_dot	isometric_projection(t_dot dot, float zoom)
{
	t_dot	result;
	float	angle;
	float	scaled_x;
	float	scaled_y;
	float	scaled_z;

	angle = M_PI / 6;
	scaled_x = dot.x * GRID_SPACING * zoom;
	scaled_y = dot.y * GRID_SPACING * zoom;
	scaled_z = dot.z * GRID_SPACING * zoom;
	result.x = (scaled_x - scaled_y) * cos(angle);
	result.y = (scaled_x + scaled_y) * sin(angle) - scaled_z;
	result.z = dot.z;
	result.color = dot.color;
	return (result);
}
