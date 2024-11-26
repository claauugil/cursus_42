/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:45:23 by cgil              #+#    #+#             */
/*   Updated: 2024/10/09 13:44:29 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	*ft_strcp(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}*/

#include <stdio.h>

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
/*int main (void)
{
	const char *hola = "hola";
	printf("%s",ft_strdup(hola));
}*/
