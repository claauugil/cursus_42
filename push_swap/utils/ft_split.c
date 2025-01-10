/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:11:21 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 18:42:47 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_counter(char const *s, char delimiter)
{
	int	i;
	int	word_index;
	int	in_word;

	i = 0;
	word_index = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != delimiter && in_word == 0)
		{
			in_word = 1;
			word_index++;
		}
		else if (s[i] == delimiter)
			in_word = 0;
		i++;
	}
	return (word_index);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/*void	free_split(int position, char **matrix)
{
	while (position >= 0)
	{
		free(matrix[position--]);
	}
	free(matrix);
}*/
static char	**fill_matrix(const char *s, char delimiter, char **matrix)
{
	int	i;
	int	start;
	int	position;

	i = 0;
	position = 0;
	while (s[i] != '\0')
	{
		while (s[i] == delimiter)
			i++;
		start = i;
		while (s[i] != delimiter && s[i] != '\0')
		{
			i++;
			if (s[i] == delimiter || s[i] == '\0')
			{
				matrix[position] = ft_substr(s, start, i - start);
				if (!matrix[position])
					return (free_split(matrix), NULL);
				position++;
			}
		}
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**matrix;

	words = word_counter(s, c);
	matrix = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!matrix)
		return (NULL);
	return (fill_matrix(s, c, matrix));
}
