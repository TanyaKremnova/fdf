/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:43:53 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:35 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	draw_line(t_dot start, t_dot end, t_fdf *fdf)
{
	t_params	params;
	t_color		colors;
	t_bdots		dots;

	modify_coordinates(&start, &end, fdf);
	if (is_outside_window(start, end))
		return ;
	init_params(&params, start, end);
	colors.start_color = start.color;
	colors.end_color = end.color;
	dots.start = &start;
	dots.end = end;
	bresenham(&dots, &params, colors, fdf);
}

void	bresenham(t_bdots *dots, t_params *params, t_color colors, t_fdf *fdf)
{
	float	ratio;
	int		color;
	int		start_x;
	int		start_y;

	dots->original_start = *(dots->start);
	while (dots->start->x != dots->end.x || dots->start->y != dots->end.y)
	{
		ratio = get_ratio(*(dots->start), dots->original_start, dots->end);
		color = color_gradient(colors.start_color, colors.end_color, ratio);
		dots->start->color = color;
		start_x = (int)(dots->start->x + BRESENHAM_ROUND);
		start_y = (int)(dots->start->y + BRESENHAM_ROUND);
		if (dots->start->x >= 0 && dots->start->x < WIDTH && dots->start->y >= 0
			&& dots->start->y < HEIGHT)
		{
			dots->pixel.x = start_x;
			dots->pixel.y = start_y;
			dots->pixel.z = dots->start->z;
			dots->pixel.color = dots->start->color;
			set_pixel(&(dots->pixel), fdf);
		}
		move_dot(dots->start, params, 2 * params->err);
	}
}

void	move_dot(t_dot *start, t_params *params, int e2)
{
	if (e2 > -params->distances.y)
	{
		params->err -= params->distances.y;
		start->x += params->signs.x;
	}
	if (e2 < params->distances.x)
	{
		params->err += params->distances.x;
		start->y += params->signs.y;
	}
}
