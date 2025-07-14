/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:47:50 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:44 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	is_outside_window(t_dot start, t_dot end)
{
	if ((start.x < 0 || start.x >= WIDTH || start.y < 0 || start.y >= HEIGHT)
		&& (end.x < 0 || end.x >= WIDTH || end.y < 0 || end.y >= HEIGHT))
	{
		return (1);
	}
	return (0);
}

void	init_params(t_params *params, t_dot start, t_dot end)
{
	params->distances.x = ft_absolute((int)(end.x - start.x));
	params->distances.y = ft_absolute((int)(end.y - start.y));
	if (start.x < end.x)
		params->signs.x = 1;
	else
		params->signs.x = -1;
	if (start.y < end.y)
		params->signs.y = 1;
	else
		params->signs.y = -1;
	params->err = params->distances.x - params->distances.y;
}

void	rotate_xy(t_dot *point, t_rotation rotat)
{
	float	origin_x;
	float	origin_y;

	origin_x = point->x;
	origin_y = point->y;
	point->x = origin_x * rotat.cos_angle - origin_y * rotat.sin_angle;
	point->y = origin_x * rotat.sin_angle + origin_y * rotat.cos_angle;
}

void	rotate_z(t_dot *point, t_rotation rotat)
{
	float	origin_y;
	float	origin_z;

	origin_y = point->y;
	origin_z = point->z;
	point->y = origin_y * rotat.cos_angle_z - origin_z * rotat.sin_angle_z;
	point->z = origin_y * rotat.sin_angle_z + origin_z * rotat.cos_angle_z;
}
