/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:43:44 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/20 00:36:05 by afailde-         ###   ########.fr       */
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
