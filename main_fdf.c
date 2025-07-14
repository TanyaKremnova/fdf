/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:54:50 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/22 10:25:11 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int	initialize_fdf(t_fdf **fdf, char *filename);
static int	create_window(t_fdf *fdf);
void		render_map(t_fdf *fdf);

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = NULL;
	if (argc != 2)
	{
		ft_printf("Provide a valid .fdf file to visualize =^-^=\n");
		return (1);
	}
	if (initialize_fdf(&fdf, argv[1]))
		return (1);
	if (create_window(fdf))
	{
		cleanup(fdf);
		return (1);
	}
	render_map(fdf);
	if (setup_hooks(fdf))
	{
		cleanup(fdf);
		return (1);
	}
	mlx_loop(fdf->win);
	cleanup(fdf);
	return (0);
}

static int	initialize_fdf(t_fdf **fdf, char *file)
{
	*fdf = malloc(sizeof(t_fdf));
	if (*fdf == NULL)
		return (1);
	(*fdf)->win = NULL;
	(*fdf)->img = NULL;
	(*fdf)->matrix = NULL;
	(*fdf)->map_width = 0;
	(*fdf)->map_height = 0;
	(*fdf)->x_offset = WIDTH / 2;
	(*fdf)->y_offset = HEIGHT / 2;
	(*fdf)->zoom = 1.0f;
	(*fdf)->projection = 0;
	(*fdf)->rotation_angle = 0.0f;
	(*fdf)->rotation_angle_z = 0.0f;
	(*fdf)->matrix = parse_fdf(file, &(*fdf)->map_width, &(*fdf)->map_height);
	if ((*fdf)->matrix == NULL)
	{
		free(*fdf);
		*fdf = NULL;
		return (1);
	}
	return (0);
}

static int	create_window(t_fdf *fdf)
{
	fdf->win = mlx_init(WIDTH, HEIGHT, "FDF =^-^= 🎉", true);
	if (fdf->win == NULL)
		return (1);
	fdf->img = mlx_new_image(fdf->win, WIDTH, HEIGHT);
	if (fdf->img == NULL)
		return (1);
	return (0);
}

void	render_map(t_fdf *fdf)
{
	clean_map(fdf, 0x262626ff);
	render_grid(fdf);
	mlx_image_to_window(fdf->win, fdf->img, 0, 0);
}
