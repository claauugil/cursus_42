/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 10:57:23 by cgil              #+#    #+#             */
/*   Updated: 2024-11-26 10:57:23 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void prep_pipe(int in_file, int out_file)
{
	//redirige de la entrada y salida de los fds
	dup2(in_file, STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
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
int main (int ac, char *av[], char *env[])
{
	int pipefds[2]; //lectura y escritura del pipe
	int in_file; //archivo de entrada
	int out_file; //archivo de salida

	//creo pipe con sus fds
	pipe(pipefds);
	//abro archivos
	in_file = open(av[1], O_RDONLY); //archivo de entrada
	out_file = open(av[4], O_WRONLY| O_TRUNC| O_CREAT, 0644);//archivo de salida

	if (!fork()) //primer hijo
	{
		prep_pipe(in_file, pipefds[1]); //redirigo salida y entrada
		close_fds(in_file, pipefds[0], pipefds[1], 0); //cierra fds no necesarios, 0 placeholder
	}
	if (!fork)
	{
		prep_pipe(pipefds[0], out_file); //
		close_fds(out_file, pipefds[1], pipefds[0], 0);
	}
}


