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

char	*concat_line(char **store, char *buffer) //**
{
	char	*temp;

	temp = ft_strjoin(*store, buffer);
	free (*store);
	return (temp);
}

int	handle_errors(char **store, char *buffer, size_t bytes_read)
{
	if (bytes_read < 0 || (bytes_read == 0
			&& (*store == NULL || **store == '\0')))
	{
		free(buffer);
		free(*store);
		*store = NULL;
		return (1);
	}
	return (0);
}

char	*tidy_lines(char **store)
{
	char	*new_line; //puntero a la direcion del primer caracter de la nueva linea
	size_t	line_len; //longitud de la linea a extraer mas el caracter nulo
	char	*line; //linea devuelta
	char	*new_store; //el resto de store si lo hay, sino NULL

	new_line = (ft_strchr(*store, '\n')); // si encuentra un salto de linea
	if (new_line)
		line_len = (new_line - *store) + 1;
	else
		line_len = ft_strlen(*store);
	line = (char *)malloc (line_len + 1); // + 1 para incluir el nulo
	ft_strlcpy(line, *store, line_len + 1); // para el nulo
	if (new_line)
	{
		new_store = ft_strdup(new_line + 1); // guardar lo que haya quedado (si lo hay)
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
	static char	*store;
	char		*buffer;
	size_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0'; //tratar buffer como cadena valida
		if (store == NULL) // para la primera lectura
			store = ft_strdup(buffer);
		else
			store = concat_line(&store, buffer); //concatenar cuando store ya no este vacio
		if (ft_strchr(store, '\n'))
			break;// si encuentra un salto de linea sale
		bytes_read = read(fd, buffer, BUFFER_SIZE); // vuelve a leer si no entra en las concidiones
	}
	if (handle_errors(&store, buffer, bytes_read))
		return (NULL);
	free(buffer);
	return (tidy_lines(&store)); //puntero para poder modificar store directamente
}
/*int main (void)
{
	int fd;
	char *line;

	fd = open ("hola.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error en la lectura");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
