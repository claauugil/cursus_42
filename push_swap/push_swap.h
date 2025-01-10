/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:00:55 by claudia           #+#    #+#             */
/*   Updated: 2025/01/10 13:21:11 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
//void	free_split(int position, char **matrix);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sort(t_stack *a, t_stack *b);
int		max(int a, int b);
void	print_error_exit(t_stack *stack_a, t_stack *stack_b);
//void	print_error(void);
int		is_biggest(t_stack *in_stack, int n);
int		is_smallest(t_stack *in_stack, int n);
int		find_biggest(t_stack *to_find);
int		find_smallest(t_stack *to_find);
int		ft_abs(int n);
int		calculate_combined_moves(int f_depth, int target_depth);
int		get_combined_moves(t_stack *from, t_stack *to, int value);
void	update_cheapest(int *actual_moves, int combined_moves,
			int *cheapest_value, int value);
int		check_cheapest(t_stack *from, t_stack *to);
int		push_cheapest(t_stack *from, t_stack *to, int val);
void	rotate_each(t_stack *from, int *val_depth, t_stack *to, int *tar_depth);
void	rotates(t_stack *from, t_stack *to, int *val_depth, int *tar_depth);
void	rotate_tgt_to(t_stack *to, int *depth);
void	rotate_f_t(t_stack *from, int *depth);
int		is_sorted(t_stack *stack);
void	sort_two(t_stack *stack);
void	bring_min_to_top(t_stack *in_stack);
void	bring_to_top(t_stack *a, int target);
int		get_depth(t_stack *in_stack, int val);
void	largest_at_top(t_stack *a);
void	smallest_in_middle(t_stack *a);
void	sort_three(t_stack *a);
void	push_back(t_stack *b, t_stack *a);
int		find_near_lower(t_stack *search, int n);
int		find_near_upper(t_stack *to_search, int target);
int		get_target(t_stack *search, int n);
int		search_dups(t_stack *stack);
int		empty_string(char *str);
int		check_errors(int argc, char **argv);
int		int_range(char *str);
t_node	*new_node(int value);
t_stack	*create_stack(void);
void	push_stack(t_stack *stack, int value);
void	init_stack(int ac, char *av[], t_stack *stack);
void	free_stack(t_stack *stack);
int		is_numeric_input(char *str);
int		many_inputs(int ac, char *av[]);
int		only_input(char *str);
int		validate_input(int ac, char *av[]);
#endif
