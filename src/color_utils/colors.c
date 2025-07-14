/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:54:22 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:24 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

float	get_ratio(t_dot current, t_dot start, t_dot end)
{
	float	total_distance;
	float	cur_dist;
	float	ratio;

	current.x *= GRID_SPACING;
	current.y *= GRID_SPACING;
	start.x *= GRID_SPACING;
	start.y *= GRID_SPACING;
	end.x *= GRID_SPACING;
	end.y *= GRID_SPACING;
	total_distance = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	cur_dist = sqrt(pow(current.x - start.x, 2) + pow(current.y - start.y, 2));
	if (total_distance == 0.0f)
		return (1.0f);
	ratio = cur_dist / total_distance;
	return (ratio);
}

static t_rgba	split_color(uint32_t rgba)
{
	t_rgba	color;

	color.r = (rgba >> 16) & 0xFF;
	color.g = (rgba >> 8) & 0xFF;
	color.b = rgba & 0xFF;
	color.a = 0xFF;
	return (color);
}

static int	clamp_color(int color)
{
	if (color < 0)
		return (0);
	else if (color > 255)
		return (255);
	return (color);
}

static int	blend_chnl(int start, int end, float ratio)
{
	return (start + (int)((end - start) * ratio));
}

int	color_gradient(int color_start, int color_end, float ratio)
{
	t_rgba	start_color;
	t_rgba	end_color;
	t_rgba	result;

	start_color = split_color(color_start);
	end_color = split_color(color_end);
	result.r = clamp_color(blend_chnl(start_color.r, end_color.r, ratio));
	result.g = clamp_color(blend_chnl(start_color.g, end_color.g, ratio));
	result.b = clamp_color(blend_chnl(start_color.b, end_color.b, ratio));
	result.a = 0xFF;
	return ((result.r << 24) | (result.g << 16) | (result.b << 8) | result.a);
}
