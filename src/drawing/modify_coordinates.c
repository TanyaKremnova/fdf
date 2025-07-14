/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:47:50 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:39 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	rotate_coordinates(t_dot *start, t_dot *end, t_rotation rotation)
{
	rotate_xy(start, rotation);
	rotate_xy(end, rotation);
	rotate_z(start, rotation);
	rotate_z(end, rotation);
}

void	apply_projection(t_dot *start, t_dot *end, t_fdf *fdf)
{
	if (fdf->projection == ISOMETRIC)
	{
		*start = isometric_projection(*start, fdf->zoom);
		*end = isometric_projection(*end, fdf->zoom);
	}
	else if (fdf->projection == TOP_DOWN)
	{
		start->x = start->x * GRID_SPACING * fdf->zoom;
		start->y = start->y * GRID_SPACING * fdf->zoom;
		end->x = end->x * GRID_SPACING * fdf->zoom;
		end->y = end->y * GRID_SPACING * fdf->zoom;
	}
	else if (fdf->projection == PARALLEL)
	{
		start->x = (start->x + start->z * Z_DEPTH_P) * GRID_SPACING * fdf->zoom;
		start->y = (start->y + start->z * Z_DEPTH_P) * GRID_SPACING * fdf->zoom;
		end->x = (end->x + end->z * Z_DEPTH_P) * GRID_SPACING * fdf->zoom;
		end->y = (end->y + end->z * Z_DEPTH_P) * GRID_SPACING * fdf->zoom;
	}
}

void	apply_offset(t_dot *start, t_dot *end, t_fdf *fdf)
{
	start->x += fdf->x_offset;
	start->y += fdf->y_offset;
	end->x += fdf->x_offset;
	end->y += fdf->y_offset;
}

void	round_coordinates(t_dot *start, t_dot *end)
{
	start->x = roundf(start->x);
	start->y = roundf(start->y);
	end->x = roundf(end->x);
	end->y = roundf(end->y);
}

void	modify_coordinates(t_dot *start, t_dot *end, t_fdf *fdf)
{
	t_rotation	rotation;

	rotation.cos_angle = cos(fdf->rotation_angle);
	rotation.sin_angle = sin(fdf->rotation_angle);
	rotation.cos_angle_z = cos(fdf->rotation_angle_z);
	rotation.sin_angle_z = sin(fdf->rotation_angle_z);
	rotate_coordinates(start, end, rotation);
	apply_projection(start, end, fdf);
	apply_offset(start, end, fdf);
	round_coordinates(start, end);
}
