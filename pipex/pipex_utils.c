/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 08:59:48 by cgil              #+#    #+#             */
/*   Updated: 2024-11-26 08:59:48 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft.h"

void prep_pipe(int in_file, int out_file)
{
	//redirige de la entrada y salida de los fds
	dup2(in_file, STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
}

char** get_path(char **env)
{
	char **path;

	while(*env)
	{
		if(ft_strncmp(*env, "PATH", 4) == 0)
			break;
		*env++;
	}
	if (*env == NULL)
		return (NULL);
	path = ft_split(*env + 5, ':');
	return(path);
}
//cierra todos los descriptores, porque ya estan duplicados
void close_fds(int fd1, int fd2, int fd3, int fd4)
{
	if (fd1 > 0)
		close (fd1);
	if (fd2 > 0)
		close (fd2);
	if (fd3 > 0)
		close (fd3);
	if (fd4 > 0)
		close (fd4);
}
