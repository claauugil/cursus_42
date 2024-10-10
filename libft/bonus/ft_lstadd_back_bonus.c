/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:32:26 by cgil              #+#    #+#             */
/*   Updated: 2024/10/04 13:52:42 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new != 0)
	{
		if (*lst == 0)
		{
			*lst = new;
			(*lst)->next = NULL;
		}
		else
			ft_lstlast(*lst)->next = new;
	}
}
