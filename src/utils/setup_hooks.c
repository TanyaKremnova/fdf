/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:17:09 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:45:23 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	setup_hooks(t_fdf *fdf)
{
	if (mlx_image_to_window(fdf->win, fdf->img, 0, 0) < 0)
		return (1);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_close_hook(fdf->win, (mlx_closefunc)close_window, fdf);
	return (0);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		close_window(fdf);
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
		reset_to_default(fdf);
	else
	{
		modify_offset(fdf, keydata);
		modify_zoom(fdf, keydata);
		change_projection(fdf, keydata);
		modify_rotation(fdf, keydata);
	}
	render_map(fdf);
}
