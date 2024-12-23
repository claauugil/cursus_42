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
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

int		ft_atoi(const char *nptr);
int		ft_isdigit(int n);
char	**ft_split(char const *s, char c);
char	**free_split(int position, char **matrix);
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
int		int_range(char *str);
int		is_numeric_input(char *str);
int		many_inputs(int ac, char *av[]);
int		only_input(char *str);
int		validate_input(int ac, char *av[]);
t_node	*new_node(int value);
t_stack	*create_stack(void);
void	push_stack(t_stack *stack, int value);
void	free_stack(t_stack *stack);
void	init_stack(int ac, char *av[], t_stack *stack);

#endif
