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

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>

void prep_pipe(int in_file, int out_file);
void handle_fork_error(void);
void close_fds(int fd1, int fd2, int fd3, int fd4);
void handle_first_child(int in_file, int *pipe_fds, char *av[1], char *env[]);
void handle_second_child(int out_file, int *pipe_fds, char *av[1], char *env[]);

#endif
