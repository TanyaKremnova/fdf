/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:03:13 by tkremnov          #+#    #+#             */
/*   Updated: 2024/11/26 10:18:01 by tkremnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*handle_leftover(char **leftover);
static char	*read_and_process(int fd, char *line, char **leftover);
static char	*process_chunk(int fd, char *line, char *chunk, char **leftover);
static char	*handle_newline(char **line, char *chunk, char **leftover);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftover;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (leftover)
		{
			free(leftover);
			leftover = NULL;
		}
		return (NULL);
	}
	line = handle_leftover(&leftover);
	if (!line)
		return (NULL);
	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		return (line);
	line = read_and_process(fd, line, &leftover);
	if (!line || ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}

static char	*handle_leftover(char **leftover)
{
	char	*newl_chr;
	char	*line;
	size_t	len;

	if (*leftover == NULL)
	{
		line = malloc(1);
		if (line)
			line[0] = '\0';
		return (line);
	}
	newl_chr = ft_strchr(*leftover, '\n');
	if (newl_chr)
		len = newl_chr - *leftover + 1;
	else
		len = ft_strlen(*leftover);
	line = malloc(len + 1);
	if (!line)
		return (free(*leftover), *leftover = NULL, NULL);
	ft_strlcpy(line, *leftover, len + 1);
	if (newl_chr)
		ft_memmove(*leftover, newl_chr + 1, ft_strlen(newl_chr + 1) + 1);
	else
		(free(*leftover), *leftover = NULL);
	return (line);
}

static char	*read_and_process(int fd, char *line, char **leftover)
{
	char	*chunk;

	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = process_chunk(fd, line, chunk, leftover);
	free(chunk);
	return (line);
}

static char	*process_chunk(int fd, char *line, char *chunk, char **leftover)
{
	ssize_t	bytes_read;
	char	*newline_result;
	char	*temp;

	bytes_read = read(fd, chunk, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(line), line = NULL, NULL);
	while (bytes_read > 0)
	{
		chunk[bytes_read] = '\0';
		newline_result = handle_newline(&line, chunk, leftover);
		if (!line)
			return (NULL);
		if (newline_result)
			return (newline_result);
		temp = malloc((ft_strlen(line) + bytes_read + 1) * sizeof(char));
		if (!temp)
			return (free(line), line = NULL, NULL);
		ft_strlcpy(temp, line, ft_strlen(line) + 1);
		ft_strlcat(temp, chunk, ft_strlen(line) + bytes_read + 1);
		free(line);
		line = temp;
		bytes_read = read(fd, chunk, BUFFER_SIZE);
	}
	return (line);
}

static char	*handle_newline(char **line, char *chunk, char **leftover)
{
	char	*newl_chr;
	char	*temp;
	size_t	len;
	size_t	new_len;

	newl_chr = ft_strchr(chunk, '\n');
	if (newl_chr)
	{
		len = newl_chr - chunk + 1;
		new_len = ft_strlen(*line) + len + 1;
		temp = malloc(new_len);
		if (!temp)
			return (free(*line), *line = NULL, NULL);
		ft_strlcpy(temp, *line, ft_strlen(*line) + 1);
		ft_strlcat(temp, chunk, new_len);
		free(*line);
		*line = temp;
		*leftover = malloc(ft_strlen(newl_chr + 1) + 1);
		if (!*leftover)
			return (free(*line), *line = NULL, NULL);
		ft_strlcpy(*leftover, newl_chr + 1, ft_strlen(newl_chr + 1) + 1);
		return (*line);
	}
	return (NULL);
}
