/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 09:01:22 by cgil              #+#    #+#             */
/*   Updated: 2024-11-26 09:01:22 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> // open y modos de apertura de archivos
# include <unistd.h>// write, close
# include <stdlib.h>//mallloc
# include <sys/wait.h> // wait
# include <sys/types.h>// pid_t, fork

void prep_pipe(int in_file, int out_file);
void fork_error(void);
void close_fds(int fd1, int fd2, int fd3, int fd4);
void handle_first_child(int in_file, int *pipe_fds, char *env[], char *bin);
void handle_second_child(int out_file, int *pipe_fds, char *env[], char *bin);

#endif
