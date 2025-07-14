/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:41:22 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:55 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_dot		**parse_fdf(const char *filename, int *width, int *height);
static int	get_height(const char *filename);
static int	open_file(const char *filename);
static int	count_lines(int fd);
static int	parse_file_rows(int fd, t_dot **matrix, int *width);

t_dot	**parse_fdf(const char *filename, int *width, int *height)
{
	t_dot	**matrix;
	int		fd;

	*width = 0;
	*height = get_height(filename);
	if (*height <= 0)
		return (NULL);
	matrix = allocate_matrix(*height);
	if (!matrix)
		return (NULL);
	fd = open_file(filename);
	if (fd < 0)
	{
		free_matrix(&matrix, *height);
		return (NULL);
	}
	if (parse_file_rows(fd, matrix, width) < 0)
	{
		free_matrix(&matrix, *height);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (matrix);
}

static int	get_height(const char *filename)
{
	int	fd;
	int	height;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Unable to open file =^-^= %s\n", filename);
		return (-1);
	}
	height = count_lines(fd);
	if (close(fd) < 0)
	{
		ft_printf("Error: Unable to close file =^-^= %s\n", filename);
		return (-1);
	}
	return (height);
}

static int	count_lines(int fd)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\0')
			height++;
		free(line);
		line = get_next_line(fd);
	}
	return (height);
}

static int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_printf("Error: Unable to open file =^-^= %s\n", filename);
	return (fd);
}

static int	parse_file_rows(int fd, t_dot **matrix, int *width)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line == '\0')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (process_line(line, matrix, width, y) < 0)
		{
			free(line);
			free_matrix(&matrix, y);
			return (-1);
		}
		free(line);
		y++;
		line = get_next_line(fd);
	}
	return (0);
}
