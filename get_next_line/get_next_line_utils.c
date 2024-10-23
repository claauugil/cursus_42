/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-23 10:19:05 by cgil              #+#    #+#             */
/*   Updated: 2024-10-23 10:19:05 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	longitud;

	longitud = 0;
	while (str[longitud] != '\0')
	{
		longitud++;
	}
	return (longitud);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < size -1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoined;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	strjoined = (char *)malloc(len1 + len2 + 1);
	if (!strjoined)
		return (NULL);
	ft_strlcpy(strjoined, s1, len1 + 1);
	ft_strlcpy(strjoined + len1, s2, len2 + 1);
	return (strjoined);
}
char	*ft_strdup(const char *s)
{
	char	*copy;
	int 	i;

	i = 0;
	copy = malloc(ft_strlen(s) + 1);
	if (!copy)
		return (NULL);

		while (s[i] != '\0')
		{
			copy[i] = s[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
}
