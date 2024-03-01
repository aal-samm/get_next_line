/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-samm <aal-samm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:05:10 by aal-samm          #+#    #+#             */
/*   Updated: 2024/03/01 02:44:17 by aal-samm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line_from_buffer(char *buffer, char *prev_line)
{
	char	*line;
	int		len;

	len = 0;
	while (buffer && buffer[len])
	{
		if (buffer[len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	line = ft_substr(buffer, 0, len);
	if (!line)
	{
		free(prev_line);
		prev_line = NULL;
		return (NULL);
	}
	free(prev_line);
	prev_line = NULL;
	return (line);
}

char	*extract_line(char **prev_line, char *buffer)
{
	int		len;
	char	*line;

	if (ft_strchr((*prev_line), '\n'))
	{
		len = 0;
		while (len < (int)ft_strlen(*prev_line))
		{
			if ((*prev_line)[len] == '\n')
			{
				len++;
				while ((*prev_line) && (*prev_line)[len])
					(*prev_line)[len++] = '\0';
			}
			len++;
		}
		return (*prev_line);
	}
	else if (ft_strchr((buffer), '\n') && !ft_strchr((*prev_line), '\n'))
	{
		line = extract_line_from_buffer(buffer, *prev_line);
		return (line);
	}
	return (*prev_line);
}

void	obtain_remaining(char *buffer)
{
	int	len;
	int	j;

	if (ft_strchr(buffer, '\n'))
	{
		len = 0;
		j = 0;
		while (buffer[len] != '\n')
			len++;
		len++;
		while (buffer[len] != '\0')
			buffer[j++] = buffer[len++];
		while (buffer[j] != '\0')
			buffer[j++] = '\0';
	}
	return ;
}

void	ft_read_to_buffer(int fd, char *main_buffer, char **line)
{
	int	bytes_num;
	int	i;

	*line = ft_strjoin_gnl(*line, main_buffer);
	i = 0;
	while (i <= BUFFER_SIZE)
		main_buffer[i++] = '\0';
	bytes_num = 1;
	while (bytes_num > 0)
	{
		bytes_num = read(fd, main_buffer, BUFFER_SIZE);
		if (bytes_num == -1)
		{
			i = 0;
			while (i <= BUFFER_SIZE)
				main_buffer[i++] = '\0';
			free(*line);
			*line = NULL;
			return ;
		}
		main_buffer[bytes_num] = '\0';
		*line = ft_strjoin_gnl(*line, main_buffer);
		if (ft_strchr(main_buffer, '\n'))
			break ;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	main_buffer[OPEN_MAX][BUFFER_SIZE + 1];
	int			i;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		i = 0;
		while (i <= BUFFER_SIZE)
			main_buffer[fd][i++] = '\0';
		return (NULL);
	}
	line = (char *)ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	if (!ft_strchr(main_buffer[fd], '\n'))
		ft_read_to_buffer(fd, main_buffer[fd], &line);
	line = extract_line(&line, main_buffer[fd]);
	obtain_remaining(main_buffer[fd]);
	if (line[0] == '\0')
		return (free(line), line = NULL, line);
	return (line);
}
