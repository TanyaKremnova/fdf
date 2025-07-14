/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:05:07 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 15:40:38 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define WIDTH 3000
# define HEIGHT 2000
# define DEFAULT_COLOR 0x0759e8
# define GRID_SPACING 20
# define BRESENHAM_ROUND 0.5f
# define ISOMETRIC 0
# define TOP_DOWN 1
# define PARALLEL 2
# define Z_DEPTH_P 0.5
# define KEY_PLUS 334
# define KEY_MINUS 333
# define KEY_MINUS 333
# define ZOOM_STEP 0.8
# define ZOOM_MIN 0.1
# define ZOOM_MAX 10.0

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_dot
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_dot;

typedef struct s_fdf
{
	void		*win;
	int			map_width;
	int			map_height;
	t_dot		**matrix;
	mlx_image_t	*img;
	int			x_offset;
	int			y_offset;
	float		zoom;
	int			projection;
	float		rotation_angle;
	float		rotation_angle_z;
}				t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct line_params
{
	t_point	distances;
	t_point	signs;
	int		err;
}			t_params;

typedef struct line_color
{
	int	start_color;
	int	end_color;
}		t_color;

typedef struct s_bresenham_dots
{
	t_dot	*start;
	t_dot	end;
	t_dot	original_start;
	t_dot	pixel;
}			t_bdots;

typedef struct s_iso_coords
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_iso_coords;

typedef struct s_rgba
{
	int	r;
	int	g;
	int	b;
	int	a;
}		t_rgba;

typedef struct s_rotation
{
	float	cos_angle;
	float	sin_angle;
	float	cos_angle_z;
	float	sin_angle_z;
}			t_rotation;

int		main(int argc, char **argv);
void	render_map(t_fdf *fdf);

t_dot	**parse_fdf(const char *filename, int *width, int *height);
int		process_line(char *line, t_dot **matrix, int *width, int y);
int		get_width(const char *line);
int		parse_point(char *point, t_dot *dot, int y, int x);
int		parse_point_row(char *line, t_dot *row, int y, int width);
t_dot	**allocate_matrix(int height);

int		setup_hooks(t_fdf *fdf);
void	key_hook(mlx_key_data_t keydata, void *param);
void	modify_offset(t_fdf *fdf, mlx_key_data_t keydata);
void	modify_zoom(t_fdf *fdf, mlx_key_data_t keydata);
void	change_projection(t_fdf *fdf, mlx_key_data_t keydata);
void	modify_rotation(t_fdf *fdf, mlx_key_data_t keydata);
void	reset_to_default(t_fdf *fdf);
void	set_pixel(t_dot *point, t_fdf *data);
void	close_window(t_fdf *data);
void	clean_map(t_fdf *fdf, uint32_t color);
void	cleanup(t_fdf *fdf);
void	free_matrix(t_dot ***matrix, int rows);
void	ft_free_split(char **split);
int		ft_absolute(int n);
int		hex_to_int(const char *hex);

void	render_grid(t_fdf *fdf);
t_dot	isometric_projection(t_dot dot, float zoom);

float	get_ratio(t_dot current, t_dot start, t_dot end);
int		color_gradient(int color_start, int color_end, float ratio);

void	draw_line(t_dot start, t_dot end, t_fdf *data);
void	bresenham(t_bdots *dots, t_params *params, t_color colors, t_fdf *fdf);
void	move_dot(t_dot *start, t_params *params, int e2);
void	modify_coordinates(t_dot *start, t_dot *end, t_fdf *fdf);
int		is_outside_window(t_dot start, t_dot end);
void	init_params(t_params *params, t_dot start, t_dot end);
void	rotate_xy(t_dot *point, t_rotation rotat);
void	rotate_z(t_dot *point, t_rotation rotat);

#endif