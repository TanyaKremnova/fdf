/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:49:22 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:59 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static char	**split_and_trim_line(char *line, char **trimmed_line);
static int	parse_all_points(char **points, t_dot *row, int y);
int			parse_point(char *point, t_dot *dot, int y, int x);
int			parse_point_row(char *line, t_dot *row, int y, int width);

int	parse_point_row(char *line, t_dot *row, int y, int width)
{
	char	**points;
	char	*trimmed_line;
	int		x;

	if (!line || !row)
		return (-1);
	points = split_and_trim_line(line, &trimmed_line);
	if (!points)
	{
		free(trimmed_line);
		return (-1);
	}
	x = parse_all_points(points, row, y);
	ft_free_split(points);
	free(trimmed_line);
	if (x < 0 || x != width)
		return (-1);
	return (0);
}

static char	**split_and_trim_line(char *line, char **trimmed_line)
{
	*trimmed_line = ft_strtrim(line, " \t\n\r");
	if (!*trimmed_line)
		return (NULL);
	return (ft_split(*trimmed_line, ' '));
}

static int	parse_all_points(char **points, t_dot *row, int y)
{
	int	x;

	x = 0;
	while (points[x])
	{
		if (parse_point(points[x], &row[x], y, x) < 0)
			return (-1);
		x++;
	}
	return (x);
}

int	parse_point(char *point, t_dot *dot, int y, int x)
{
	char	*trimmed_point;
	char	**parts;

	trimmed_point = ft_strtrim(point, " \t\n\r");
	if (!trimmed_point || ft_strlen(trimmed_point) == 0)
	{
		free(trimmed_point);
		return (0);
	}
	parts = ft_split(trimmed_point, ',');
	if (!parts)
	{
		free(trimmed_point);
		return (-1);
	}
	dot->x = (float)x;
	dot->y = (float)y;
	dot->z = (float)ft_atoi(parts[0]);
	if (parts[1] && hex_to_int(parts[1]) != -1)
		dot->color = hex_to_int(parts[1]);
	else
		dot->color = DEFAULT_COLOR;
	ft_free_split(parts);
	free(trimmed_point);
	return (0);
}
