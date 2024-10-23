/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-23 09:02:46 by cgil              #+#    #+#             */
/*   Updated: 2024-10-23 09:02:46 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>*/

char	*get_next_line(int fd)
{
	static char	*store = NULL;
	char		*buffer;
	int			bytes_read;

	if (fd <= 0 | BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer,BUFFER_SIZE);
	//while (bytes_read > 0)
	if (bytes_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (bytes_read == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0'; //cerrar en nulo
	return (buffer);
}
int main (void)
{
	int fd = open ("hola.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al leer el archivo");
		return 1;
	}

	char *line = get_next_line(fd);
	if (line)
	{
		printf("Leido: %s\n", line);
		free(line);
	}
	close (fd);
	return (0);
}
