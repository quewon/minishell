/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <qchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:01:59 by qchin             #+#    #+#             */
/*   Updated: 2026/04/02 22:23:26 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*trim_anl(char *buffer)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] != '\0')
		i++;
	if (ft_strlen(buffer) - i <= 0)
		return (NULL);
	result = malloc(ft_strlen(buffer) - i + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (buffer[i])
		result[j++] = buffer[i++];
	result[j] = '\0';
	return (result);
}

static char	*trim_bnl(char *buffer)
{
	char	*result;
	int		i;
	int		size;

	size = 0;
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	if (size == 0)
		return (NULL);
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
		result[i++] = *(buffer++);
	result[i] = '\0';
	return (result);
}

static char	*fill_buffer(int fd, char *result)
{
	char	*buffer;
	int		bytes;

	if (result && ft_strchr(result, '\n'))
		return (result);
	buffer = malloc(8 + 1);
	while (1)
	{
		bytes = read(fd, buffer, 8);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free(result);
			result = NULL;
			break ;
		}
		buffer[bytes] = '\0';
		ft_strcat(&result, buffer);
		if (!result || ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*prev_buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = fill_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	prev_buffer = buffer;
	line = trim_bnl(buffer);
	buffer = trim_anl(buffer);
	free(prev_buffer);
	if (!line)
		free(buffer);
	return (line);
}
