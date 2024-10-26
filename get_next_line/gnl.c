/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-26 13:25:16 by cgil              #+#    #+#             */
/*   Updated: 2024-10-26 13:25:16 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat_store(char **store, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*store, buffer);
	free(*store);
	return (temp);
}
int	handle_errors(char **store, char *buffer, size_t bytes_read)
{
	if (bytes_read < 0 || (bytes_read == 0
			&& (*store == NULL || **store == '\0')))
	{
		//free(buffer);
		free (*store);
		*store = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*store = NULL;
	char		*buffer;
	size_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (store == NULL)
			store = ft_strdup(buffer);
		else
			store = concat_store(&store, buffer);
		if (ft_strchr(store, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (handle_errors(&store, buffer, bytes_read))
		return (NULL);
	free(buffer);
	return (tidy_lines(&store));
}
