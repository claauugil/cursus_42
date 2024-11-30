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
#include "libft/libft.h"

void prep_pipe(int in_file, int out_file)
{
	//redirige de la entrada y salida de los fds
	dup2(in_file, STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
}
void exec(char *cmd, char *env[])
{
	char **args;
	char **paths;

	paths = get_path(env);
	args = ft_split(cmd, ' ');
	args[0]= get_exec(args[0], paths);
	execve(args[0], args, env);
}
char** get_path(char **env) // recibe variables de entorno (array de arrays)
{
	char **paths; //array de arrays

	while(*env) //busca en el de variables de entorno
	{
		if(ft_strncmp(*env, "PATH", 4) == 0) // las primeras 4 letras de cada string
			break; // si la encuentra sale
		env++;
	}
	if (*env == NULL)
	{
		write(2, "ERROR: PATH variable not found\n", 32);
		exit(EXIT_FAILURE); // salida inmediata del PROGRAMA
	}
	paths = ft_split(*env + 5, ':'); // y separa los directorios por :
	return(paths); // retorna un array de arrays que contiene los directorios
}

//busca el exec dentro de la ruta de paths y devuelve la ruta completa
//del ejecutable, o NULL si no lo encuentra
char *get_exec(char *cmd, char **paths)
{
	char *path;
	//verifica si es un comando local, dentro del directorio actual
	/*if (ft_strncmp(cmd, "./", 2) == 0 && access(cmd, X_OK))
		return(ft_strdup(cmd));*/
	while(*paths) // busca en los directorios
	{
		path = ft_strjoin(*paths, "/"); // une con / ruta relativa
		path = ft_strjoin(path, cmd); // une la ruta con el comando
		if (access(path, X_OK) == 0) // revisa si el archivo al que apunta la ruta es ejecutable
			return(path); // si lo es retorna la ruta
		paths++; // sino prueba con la siguiente
	}
	return (NULL);
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
