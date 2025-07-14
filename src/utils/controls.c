/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:17:09 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:59:27 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	modify_offset(t_fdf *fdf, mlx_key_data_t keydata)
{
	int	offset_change;

	offset_change = 16;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		fdf->y_offset -= offset_change;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		fdf->y_offset += offset_change;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		fdf->x_offset -= offset_change;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		fdf->x_offset += offset_change;
}

void	modify_zoom(t_fdf *fdf, mlx_key_data_t keydata)
{
	if (keydata.key == KEY_PLUS && keydata.action == MLX_RELEASE
		&& fdf->zoom > ZOOM_MIN)
		fdf->zoom /= ZOOM_STEP;
	else if (keydata.key == KEY_MINUS && keydata.action == MLX_RELEASE
		&& fdf->zoom < ZOOM_MAX)
		fdf->zoom *= ZOOM_STEP;
}

void	change_projection(t_fdf *fdf, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_RELEASE)
		fdf->projection = ISOMETRIC;
	else if (keydata.key == MLX_KEY_T && keydata.action == MLX_RELEASE)
		fdf->projection = TOP_DOWN;
	else if (keydata.key == MLX_KEY_P && keydata.action == MLX_RELEASE)
		fdf->projection = PARALLEL;
}

void	modify_rotation(t_fdf *fdf, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		fdf->rotation_angle += 0.1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		fdf->rotation_angle -= 0.1;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		fdf->rotation_angle_z += 0.1;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		fdf->rotation_angle_z -= 0.1;
}

void	reset_to_default(t_fdf *fdf)
{
	fdf->x_offset = WIDTH / 2;
	fdf->y_offset = HEIGHT / 2;
	fdf->zoom = 1.0f;
	fdf->rotation_angle = 0.0f;
	fdf->rotation_angle_z = 0.0f;
	fdf->projection = ISOMETRIC;
}
