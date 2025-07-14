/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:49:22 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:51 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	get_width(const char *line);
int	process_line(char *line, t_dot **matrix, int *width, int y);

int	get_width(const char *line)
{
	int		width;
	char	**points;
	char	*trimmed_line;

	trimmed_line = ft_strtrim(line, " \t\n\r");
	if (!trimmed_line)
		return (-1);
	if (trimmed_line[0] == '\0')
	{
		free(trimmed_line);
		return (0);
	}
	points = ft_split(trimmed_line, ' ');
	if (!points)
	{
		free(trimmed_line);
		return (-1);
	}
	width = 0;
	while (points[width])
		width++;
	ft_free_split(points);
	free(trimmed_line);
	return (width);
}

int	process_line(char *line, t_dot **matrix, int *width, int y)
{
	if (!line || !matrix || !width)
		return (-1);
	if (y == 0)
	{
		*width = get_width(line);
		if (*width <= 0)
			return (-1);
	}
	if (y > 0 && *width <= 0)
		return (-1);
	matrix[y] = malloc(sizeof(t_dot) * (*width));
	if (!matrix[y])
	{
		free_matrix(&matrix, y);
		return (-1);
	}
	if (parse_point_row(line, matrix[y], y, *width) < 0)
	{
		free_matrix(&matrix, y);
		return (-1);
	}
	return (0);
}
