/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 13:21:40 by cgil              #+#    #+#             */
/*   Updated: 2024-10-29 13:21:40 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*concat_line(char **store, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*store, buffer);
	free(*store);
	return (temp);
}

int	handle_errors(char **store, char *buffer, ssize_t bytes_read)
{
	if (bytes_read < 0 || (bytes_read == 0
			&& (*store == NULL || **store == '\0')))
	{
		free (buffer);
		free (*store);
		*store = NULL;
		return (1);
	}
	return (0);
}

char	*tidy_lines(char **store)
{
	char	*new_line;
	size_t	line_len;
	char	*line;
	char	*new_store;

	new_line = ft_strchr(*store, '\n');
	if (new_line)
		line_len = (new_line - *store + 1);
	else
		line_len = ft_strlen(*store);
	line = (char *)malloc(line_len + 1);
	ft_strlcpy(line, *store, line_len + 1);
	if (new_line)
	{
		new_store = ft_strdup(new_line + 1);
		free(*store);
		*store = new_store;
	}
	else
	{
		free(*store);
		*store = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*store[1024];
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (store[fd] == NULL)
			store[fd] = ft_strdup(buffer);
		else
			store[fd] = concat_line(&store[fd], buffer);
		if (ft_strchr(store[fd], '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (handle_errors(&store[fd], buffer, bytes_read))
		return (NULL);
	free (buffer);
	return (tidy_lines(&store[fd]));
}
#include <stdio.h>

int main (int argc, char *argv[])
{
	int 	fd;
	char	*line;
	int		i;

	i = 1;

	if(argc < 2)
	{
		printf("No hay suficientes argumentos");
		return (1);
	}
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			printf("Error al leer el archivo");
			continue;
		}
		printf("Lee: %s\n", argv[i]);
		while ((line = get_next_line(fd))!= NULL)
		{
			printf("%s", line);
			free(line);
		}
		close (fd);
		printf("\n");
		i++;
	}
}
int main (int argc, char **argv)
{
	int fd;
	char *line;
	int i = 1;

	if (argc < 2)
	{
		printf("No hay suficientes argumentos");
		return (1);
	}
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			printf("Error al leer el descriptor");
			continue;
		}
		printf("Lee %s\n", argv[i]);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s\n", line);
			free(line);
		}
		close(fd);
		printf("\n");
		i++;
	}
}

#include <stdio.h>
int main (int argc, char **argv)
{
	int fd;
	char *line;
	int i = 1;
	if (argc < 2)
	{
		printf("No hay suficientes argumentos");
		return (1);
	}
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			printf("Error");
			continue;
		}
		printf("Lee %s:\n", argv[i]);
		while((line = get_next_line(fd))!= NULL)
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
		printf("\n");
		i++;
	}
}
