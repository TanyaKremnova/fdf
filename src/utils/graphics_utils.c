/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:54:26 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:45:14 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	set_pixel(t_dot *point, t_fdf *fdf)
{
	uint32_t	color;

	color = point->color;
	if (point->x >= 0 || point->x < fdf->map_width || point->y >= 0
		|| point->y < fdf->map_height)
		mlx_put_pixel(fdf->img, point->x, point->y, point->color);
}

void	close_window(t_fdf *fdf)
{
	cleanup(fdf);
	exit(0);
}

void	clean_map(t_fdf *fdf, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(fdf->img, x, y, color);
			x++;
		}
		y++;
	}
}
