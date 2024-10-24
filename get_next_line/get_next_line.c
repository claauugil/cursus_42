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

char	*get_next_line(int fd)
{
	char	*store;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) *sizeof (char));
	if (!buffer)
		return (NULL);
}

/*char	*get_next_line(int fd)
{
	static char	*store = NULL; // guardar la linea leida por buffer
	char		*buffer; // guarda temporalmente la linea leida (no se puede guardar direcctamente en store)
	int			bytes_read;  //cantidad de datos leidos
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0) //problema al leer
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	while ((bytes_read = read(fd, buffer,BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (store == NULL) //termino de leer
			store = ft_strdup(buffer); //guardo en store la primera linea leida
		else
		{
			temp = ft_strjoin(store, buffer);
			free(store);
			store = temp;
		}
		if (ft_strchr(store, '\n'))
			break;
	}
	free (buffer);
	if (bytes_read < 0)
		return (NULL);
	if (store == NULL || *store == '\0')
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	line = extract_line(store);
	store = rest_of_line(store);
	return (line);
}
char	*extract_line(char *store)
char 	*rest_of_line();
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
}*/
