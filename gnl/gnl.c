/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-25 16:25:25 by cgil              #+#    #+#             */
/*   Updated: 2024-10-25 16:25:25 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

/*char	*get_next_line(int fd)
{
	static char *store = NULL;
	char		*buffer;
	size_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0);
	return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (store == NULL)
			store = ft_strdup(buffer);
		else
			store = concat_lines(&store, buffer);
		if (ft_strchr(store, '\n'))
			break;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (handle_errors(&store, buffer, bytes_read))
		return (NULL);
	free(buffer);
	return (tidy_line(&store));
}*/
char	*get_next_line(int fd)
{
	static char	*store; //datos no devueltos en las lineas anteriores
	char		*buffer; // almacenamiento temporal de datos leidos
	size_t		bytes_read; //cantidad de byte leidos

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (store == NULL) //para la primera leida
			store = ft_strdup(buffer); // copio buffer en store
		else
			store = concat_lines(&store, buffer); // si hay datos en store concateno
		if (ft_strchr(store, '\n'))
			break;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (handle_errors(&store, buffer, bytes_read))
		return (NULL);
	free(buffer);
	return (tidy_lines(&store));
}
