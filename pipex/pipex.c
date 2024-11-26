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

int main (int ac, char *av[], char *env[])
{
	int pipefds[2];
	int in_file;
	int out_file;
	//creo pipe con sus fds
	pipe(pipefds);
	//abro archivos
	in_file = open(av[1], O_RDONLY);
	out_file = open(av[4], O_WRONLY| O_TRUNC| O_CREAT, 0644);

	if (!fork())
	{
		
	}
}

