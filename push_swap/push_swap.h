/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:05:17 by cgil              #+#    #+#             */
/*   Updated: 2025/01/03 17:53:30 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
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
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
void    free_split(int position, char **matrix);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	print_error(void);
int		scan_error(int ac, char *av[]);
int		search_dups(t_stack *stack);
// int		search_dups(int ac, char *av[]);
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
void	sort_two(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_three(t_stack *a);
int		max(int a, int b);
int		is_biggest(t_stack *in_stack, int n);
int		is_smallest(t_stack *in_stack, int n);
int		find_biggest(t_stack *to_find);
int		find_smallest(t_stack *to_find);
int		get_depth(t_stack *in_stack, int val);
int		ft_abs(int n);
void	bring_to_top(t_stack *a, int target);
void	bring_min_to_top(t_stack *in_stack);
int		calculate_combined_moves(int f_depth, int target_depth);
int		get_combined_moves(t_stack *from, t_stack *to, int value);
void	update_cheapest(int *actual_moves, int combined_moves,
			int *cheapest_value, int value);
int		check_cheapest(t_stack *from, t_stack *to);
int		get_target(t_stack *search, int n, int up_low);
int		find_near_lower(t_stack *search, int n);
int		find_near_upper(t_stack *to_search, int target);
void	rotate_f_t(t_stack *from, int *depth);
void	rotate_tgt_to(t_stack *to, int *depth);
void	rotates(t_stack *from, t_stack *to, int *val_depth, int *tar_depth);
void	rotate_each(t_stack *from, int *val_depth, t_stack *to, int *tar_depth);
int		push_cheapest(t_stack *from, t_stack *to, int val);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif
