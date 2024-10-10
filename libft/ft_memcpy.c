/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:18:57 by cgil              #+#    #+#             */
/*   Updated: 2024/10/07 11:15:03 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*source;
	size_t		i;

	d = (char *)dest;
	source = (const char *)src;
	if (!d && !source)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = source[i];
		i++;
	}
	return (dest);
}
