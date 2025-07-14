/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:54:39 by tkremnov          #+#    #+#             */
/*   Updated: 2025/01/23 14:45:20 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	cleanup(t_fdf *fdf)
{
	if (fdf->img)
	{
		mlx_delete_image(fdf->win, fdf->img);
		fdf->img = NULL;
	}
	if (fdf->matrix)
	{
		free_matrix(&fdf->matrix, fdf->map_height);
		fdf->matrix = NULL;
	}
	if (fdf->win)
	{
		mlx_close_window(fdf->win);
		mlx_terminate(fdf->win);
		fdf->win = NULL;
	}
	free(fdf);
}

void	free_matrix(t_dot ***matrix, int rows)
{
	int	i;

	if (!matrix || !*matrix || rows <= 0)
		return ;
	i = 0;
	while (i < rows)
	{
		if ((*matrix)[i] != NULL)
		{
			free((*matrix)[i]);
			(*matrix)[i] = NULL;
		}
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}
