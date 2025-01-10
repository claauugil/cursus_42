/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:12:57 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 18:06:30 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
