/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:16:54 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:45:06 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	draw_horizontal_line(t_fdf *fdf, int i, int j)
{
	t_dot	start;
	t_dot	end;

	start = fdf->matrix[i][j];
	end = fdf->matrix[i][j + 1];
	if ((start.x >= 0 && start.x < WIDTH && start.y >= 0 && start.y < HEIGHT)
		&& (end.x >= 0 && end.x < WIDTH && end.y >= 0 && end.y < HEIGHT))
	{
		draw_line(start, end, fdf);
	}
}

static void	draw_vertical_line(t_fdf *fdf, int i, int j)
{
	t_dot	start;
	t_dot	end;

	start = fdf->matrix[i][j];
	end = fdf->matrix[i + 1][j];
	if ((start.x >= 0 && start.x < WIDTH && start.y >= 0 && start.y < HEIGHT)
		&& (end.x >= 0 && end.x < WIDTH && end.y >= 0 && end.y < HEIGHT))
	{
		draw_line(start, end, fdf);
	}
}

void	render_grid(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map_height)
	{
		j = 0;
		while (j < fdf->map_width)
		{
			if (j < fdf->map_width - 1)
				draw_horizontal_line(fdf, i, j);
			if (i < fdf->map_height - 1)
				draw_vertical_line(fdf, i, j);
			j++;
		}
		i++;
	}
}
