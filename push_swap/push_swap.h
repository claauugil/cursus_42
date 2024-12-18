/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 11:05:17 by cgil              #+#    #+#             */
/*   Updated: 2024-12-17 11:05:17 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev; //puntero al nodo anterior
	struct s_node	*next; //puntero al siguiente
}					t_node;

typedef struct s_stack
{
	t_node			*top; //nodo superior de la pila, ultimo agregado
	t_node			*bottom; //nodo inferior de la pila, primero agregado
	int				size; //numero de elementos en la pila
}					t_stack;

int		ft_atoi(const char *nptr);
int		ft_isdigit(int n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	print_error(void);
int		scan_error(int ac, char *av[]);
int		search_dups(t_stack *stack);
int		empty_string(char *str);

#endif
